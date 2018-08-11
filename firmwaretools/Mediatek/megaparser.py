#!/usr/bin/python
from binascii import hexlify, unhexlify
import struct
import datetime
import sys
import lzma as xz

filename = sys.argv[1]
with open(filename, "rb") as file: 
	s = file.read() 
	print(str(len(s)) + ' bytes')
	print "Magic: %s" % s[:3]
	sections = int(hex( struct.unpack( '<I', s[4:8] ) [0] ),0)
	print "Sections: %d" % sections
	print "SHA-1 Hash header: %s" % hexlify(s[136:155])
	syntax = "";
	sectionsyntax = "SECTIONS\n{\n";
	for i in range(1,sections+1):
		print "+ Section %d" % i
		offset = hex( struct.unpack( '<I', s[32*(i-1)+8:32*(i-1)+12] ) [0] )
		print "  Offset: %s" % offset
		sectionsize = int(hex( struct.unpack( '<I', s[32*(i-1)+16:32*(i-1)+20] ) [0] ),0)
		print "  Size of Section: %d (%s)" % (sectionsize,hex( struct.unpack( '<I', s[32*(i-1)+16:32*(i-1)+20] ) [0] ))
		memaddr = hex( struct.unpack( '<I', s[32*(i-1)+12:32*(i-1)+16] ) [0] )
		print "  Memaddr: %s" % memaddr
		print "  Checksum?: %s" % hexlify (s[int(offset,0)+sectionsize:int(offset,0)+sectionsize+20])
		sfile = open("section%d_%s.bin.lzma" % (i,memaddr),"wb") 
		sfile.write(s[int(offset,0):int(offset,0)+sectionsize]) 
		sfile.close() 
		if i == 1:
			startaddr = memaddr
			syntax = "arm-none-eabi-objcopy -I binary -O elf32-littlearm --set-start %s --adjust-vma %s --binary-architecture arm --rename-section .data=.text,contents,alloc,load,readonly,code " % (startaddr,memaddr)
			syntaxend = "section%d_%s.bin %s_patched.elf \n" % (i,memaddr,filename)
			sectionsyntax = sectionsyntax + ". = %s;\n.text : { *(.text) }\n" % (memaddr)
		else:
			syntax = syntax + "--add-section .text%d=section%d_%s.bin --set-section-flags .text%d=contents,alloc,load,readonly,code --change-section-address .text%d=%s " % (i,i,memaddr,i,i,memaddr)
			sectionsyntax = sectionsyntax + ". = %s;\n.text%d : { *(.text) }\n" % (memaddr,i)
	bfile = open("builder_%s_script.sh" % (filename),"w") 
	bfile.write(syntax)
	bfile.write(syntaxend)
	bfile.write("arm-none-eabi-ld %s_patched.elf -e %s -T %s_script.lds \n" % (filename,startaddr,filename))
	bfile.close() 
	secfile = open("%s_script.lds" % (filename),"w") 
	secfile.write(sectionsyntax)
	secfile.write("\n}\n")
	secfile.close() 
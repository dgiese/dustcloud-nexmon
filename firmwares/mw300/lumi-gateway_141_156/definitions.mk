NEXMON_CHIP=CHIP_VER_MW300_GW
NEXMON_CHIP_NUM=`$(NEXMON_ROOT)/buildtools/scripts/getdefine.sh $(NEXMON_CHIP)`
NEXMON_FW_VERSION=FW_VER_MW300_GW_141_151
NEXMON_FW_VERSION_NUM=`$(NEXMON_ROOT)/buildtools/scripts/getdefine.sh $(NEXMON_FW_VERSION)`

NEXMON_ARCH=armv7-m

RAM_FILE=section2_0x1f003740.bin
RAMSTART=0x1f003740
RAMSIZE=0x827DF

PATCHSTART=0x1F085F1F # RAMSTART + RAMSIZE
PATCHSIZE=0x500

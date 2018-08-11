#pragma NEXMON targetregion "patch"

#include <firmware_version.h>
#include <patcher.h>
#include <wrapper.h>




void
ping_server(char *url)
{
	http_session_t handle;
	http_resp_t *resp = 0;
	wmprintf("Register at Server with url:\r\n");
	wmprintf(url);
	wmprintf("\r\n");
	httpc_get(url, &handle, &resp, 0);
}

int
hook(char *buffer, int a, const char *format, ...) {
	wmprintf("=== Dustcloud Registration ===\r\n");
	const char * aTag_mac = (const char *)0x2000037E;
	const char * aTag_did = (const char *)0x20000386;
	const char * aTag_key = (const char *)0x2000038E;
	char hookbuffer[140];
	char hexkey[48];
	bin2hex(aTag_key, hexkey, 16, 48);
	snprintf(hookbuffer,135,"http://192.168.1.2/register.php?key=%s",hexkey);
	ping_server(hookbuffer);
	return snprintf(buffer, a, format); // Jump into original function to not break functionality
}	
// Trigger at snprintf in otu_timer_info
__attribute__((at(0x1F046152, "", CHIP_VER_MW300_GW, FW_VER_MW300_GW_141_156)))
BLPatch(hook, hook);

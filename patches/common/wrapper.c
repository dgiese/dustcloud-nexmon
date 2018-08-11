/***************************************************************************
 *                                                                         *
 *          ###########   ###########   ##########    ##########           *
 *         ############  ############  ############  ############          *
 *         ##            ##            ##   ##   ##  ##        ##          *
 *         ##            ##            ##   ##   ##  ##        ##          *
 *         ###########   ####  ######  ##   ##   ##  ##    ######          *
 *          ###########  ####  #       ##   ##   ##  ##    #    #          *
 *                   ##  ##    ######  ##   ##   ##  ##    #    #          *
 *                   ##  ##    #       ##   ##   ##  ##    #    #          *
 *         ############  ##### ######  ##   ##   ##  ##### ######          *
 *         ###########    ###########  ##   ##   ##   ##########           *
 *                                                                         *
 *            S E C U R E   M O B I L E   N E T W O R K I N G              *
 *                                                                         *
 * This file is part of NexMon.                                            *
 *                                                                         *
 * Copyright (c) 2016 NexMon Team                                          *
 *                                                                         *
 * NexMon is free software: you can redistribute it and/or modify          *
 * it under the terms of the GNU General Public License as published by    *
 * the Free Software Foundation, either version 3 of the License, or       *
 * (at your option) any later version.                                     *
 *                                                                         *
 * NexMon is distributed in the hope that it will be useful,               *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *
 * GNU General Public License for more details.                            *
 *                                                                         *
 * You should have received a copy of the GNU General Public License       *
 * along with NexMon. If not, see <http://www.gnu.org/licenses/>.          *
 *                                                                         *
 **************************************************************************/

#ifndef WRAPPER_C
#define WRAPPER_C

#include <firmware_version.h>
#include <structs.h>

#ifndef WRAPPER_H
    // if this file is not included in the wrapper.h file, create dummy functions
    #define VOID_DUMMY { ; }
    #define RETURN_DUMMY { ; return 0; }

    #define AT(CHIPVER, FWVER, ADDR) __attribute__((at(ADDR, "dummy", CHIPVER, FWVER)))
#else
    // if this file is included in the wrapper.h file, create prototypes
    #define VOID_DUMMY ;
    #define RETURN_DUMMY ;
    #define AT(CHIPVER, FWVER, ADDR)
#endif

typedef int bool;

typedef int http_session_t;

typedef enum {
	HTTP_VER_1_0,
	HTTP_VER_1_1,
} http_ver_t;

/**
 * Structure used to give back http header response fields to the caller.
 */
typedef struct {
	/** The value of the protocol field in the first line of the HTTP
	    header response. e.g. "HTTP". */
	const char *protocol;
	/** HTTP version */
	http_ver_t version;
	/** The status code returned as a part of the first line of the
	    HTTP response e.g. 200 if success
	*/
	int status_code;
	/** The ASCII string present in the first line of HTTP response. It
	    is the verbose representation of status code. e.g. "OK" if
	    status_code is 200
	*/
	const char *reason_phrase;
	/** HTTP "Server" header field value */
	const char *server;
#ifdef CONFIG_ENABLE_HTTPC_MODIFY_TIME
	/** Last-Modified header field value in POSIX time format */
	time_t modify_time;
#endif	/* CONFIG_ENABLE_HTTPC_MODIFY_TIME	*/
	/** The value of "Content-Type" header field. e.g. "text/html" */
	const char *content_type;
	/** The value of "Content-Encoding" header field e.g. "gzip" */
	const char *content_encoding;
	/** If "Keep-Alive" field is present or if the value of
	    "Connection" field is "Keep-Alive" then this member is set to
	    'true'. It is set to 'false' in other cases
	*/
	bool keep_alive_ack;
	/** If "Keep-Alive" field is present in the response, this member
	    contains the value of the "timeout" sub-field of this
	    field. This is the time the server will allow an idle
	    connection to remain open before it is closed.
	*/
	int keep_alive_timeout;
	/** If "Keep-Alive" field is present in the response, this member
	    contains the value of the "max" sub-field of this field. The
	    max parameter indicates the maximum number of requests that a
	    client will make, or that a server will allow to be made on the
	    persistent connection.
	*/
	int keep_alive_max;
	/** This will be 'true' if "Transfer-Encoding" field is set to
	    "chunked". Note that this is only for information and the API
	    http_read_content() transparently handles chunked reads.
	*/
	bool chunked;
	/** Set to 'true' when "Content-Length" header field is present in
	    server response.
	 */
	bool content_length_field_present;
	/** Value of the "Content-Length" field. If "Transfer-Encoding" is
	    set to chunked then this value will be zero. If
	    'content_length_present' is 'false' ignore this field value.
	*/
	int content_length;
} http_resp_t;

AT(CHIP_VER_MW300_LED, FW_VER_MW300_LED_141_40, 0x1F01ABF4)
AT(CHIP_VER_MW300_GW, FW_VER_MW300_GW_141_150, 0x1F045890)
AT(CHIP_VER_MW300_GW, FW_VER_MW300_GW_141_151, 0x1F046A00)
AT(CHIP_VER_MW300_GW, FW_VER_MW300_GW_141_156, 0x1F04C50C)
AT(CHIP_VER_MW300_COLORBULB1, FW_VER_MW300_COLORBULB1_141_56, 0x1F01AD94)
AT(CHIP_VER_MW300_MONO1, FW_VER_MW300_MONO1_142_0055, 0x1F01AA84)
int 
httpc_get(const char *url_str, http_session_t *handle, http_resp_t **http_resp, int null) 
RETURN_DUMMY

AT(CHIP_VER_MW300_LED, FW_VER_MW300_LED_141_40, 0x1F0178A8)
AT(CHIP_VER_MW300_GW, FW_VER_MW300_GW_141_150, 0x1F06A9F4)
AT(CHIP_VER_MW300_GW, FW_VER_MW300_GW_141_151, 0x1F06BB64)
AT(CHIP_VER_MW300_GW, FW_VER_MW300_GW_141_156, 0x1F071670)
AT(CHIP_VER_MW300_COLORBULB1, FW_VER_MW300_COLORBULB1_141_56, 0x1F017A48)
AT(CHIP_VER_MW300_MONO1, FW_VER_MW300_MONO1_142_0055, 0x1F0176FC)
void bin2hex(char *src, char *dest, unsigned int src_len,
		unsigned int dest_len)
VOID_DUMMY

AT(CHIP_VER_MW300_LED, FW_VER_MW300_LED_141_40, 0x1F018238)
AT(CHIP_VER_MW300_GW, FW_VER_MW300_GW_141_150, 0x1F0423C4)
AT(CHIP_VER_MW300_GW, FW_VER_MW300_GW_141_151, 0x1F043534)
AT(CHIP_VER_MW300_GW, FW_VER_MW300_GW_141_156, 0x1F04903C)
AT(CHIP_VER_MW300_COLORBULB1, FW_VER_MW300_COLORBULB1_141_56, 0x1F01842C)
AT(CHIP_VER_MW300_MONO1, FW_VER_MW300_MONO1_142_0055, 0x1F0180AA)
int
snprintf(char *buffer, int a, const char *format,...)
RETURN_DUMMY

AT(CHIP_VER_MW300_LED, FW_VER_MW300_LED_141_40, 0x1F017098)
AT(CHIP_VER_MW300_GW, FW_VER_MW300_GW_141_150, 0x1F0416E4)
AT(CHIP_VER_MW300_GW, FW_VER_MW300_GW_141_151, 0x1F042854)
AT(CHIP_VER_MW300_GW, FW_VER_MW300_GW_141_156, 0x1F04835C)
AT(CHIP_VER_MW300_COLORBULB1, FW_VER_MW300_COLORBULB1_141_56, 0x1F017238)
AT(CHIP_VER_MW300_MONO1, FW_VER_MW300_MONO1_142_0055, 0x1F016EEC)
int 
wmprintf(const char *format, ...) 
RETURN_DUMMY



#undef VOID_DUMMY
#undef RETURN_DUMMY
#undef AT

#endif /*WRAPPER_C*/

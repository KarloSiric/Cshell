/*======================================================================
   File: scommon.c
   Project: shell
   Author: ksiric <email@example.com>
   Created: 2026-02-24 01:14:20
   Last Modified by: ksiric
   Last Modified: 2026-02-24 20:27:45
   ---------------------------------------------------------------------
   Description:

   ---------------------------------------------------------------------
   License:
   Company:
   Version: 0.1.0
 ======================================================================
																	   */

#include "scommon.h"

void Com_Printf( const char *fmt, ... ) {
	va_list args;
	char buffer[4096];
	va_start( args, fmt );
	vsnprintf( buffer, sizeof( buffer ), fmt, args );
	va_end( args );
	fprintf( stderr, "%s: %s", SHELL_NAME, buffer );
}

void Com_FPrintf( FILE *fstream, const char *fmt, ... ) {
	va_list args;
	char buffer[4096];
	va_start( args, fmt );
	vsnprintf( buffer, sizeof( buffer ), fmt, args );
	va_end( args );
	fprintf( fstream, "%s: %s", SHELL_NAME, buffer );
}

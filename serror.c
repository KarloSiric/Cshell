/*======================================================================
   File: serror.c
   Project: shell
   Author: ksiric <email@example.com>
   Created: 2026-02-24 00:49:23
   Last Modified by: ksiric
   Last Modified: 2026-02-24 20:27:50
   ---------------------------------------------------------------------
   Description:

   ---------------------------------------------------------------------
   License:
   Company:
   Version: 0.1.0
 ======================================================================
																	   */

#include "serror.h"
#include "scommon.h"

void Err_Printf( const char *fmt, ... ) {
	va_list vargs;
	va_start( vargs, fmt );
	vfprintf( stderr, fmt, vargs );
	va_end( vargs );
}

void Err_FPrintf( FILE *fstream, const char *fmt, ... ) {
	va_list args;
	char buffer[4096];
	va_start( args, fmt );
	vsnprintf( buffer, sizeof( buffer ), fmt, args );
	va_end( args );
	fprintf( fstream, "%s: %s", SHELL_NAME, buffer );
}

void Err_Print( serror_t error_code, const char *fmt, ... ) {
	va_list args;
	va_start( args, fmt );
	char buffer[4096];
	vsnprintf( buffer, sizeof( buffer ), fmt, args );
	va_end( args );
	fprintf( stderr, "%s: %s", SHELL_NAME, serror_strings[error_code] );
	fprintf( stderr, "%s: %s", SHELL_NAME, buffer );
}

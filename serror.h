#ifndef __SERROR_H__
#define __SERROR_H__

#include "scommon.h"
#include <errno.h>
#include <stdarg.h>

#define ERR_PRINTF( ... )           Err_Printf( __VA_ARGS__ );
#define ERR_FPRINF( stream, ... )   Err_FPrintf( stream, __VA_ARGS__ );
#define ERR_PRINT( error, ... )     Err_Print( error, __VA_ARGS__ );

typedef enum {
    
    SERR_NONE = 0,
    SERR_MEMORY, 
    SERR_FORK,
    SERR_EXEC,
    SERR_CMD_NOT_FOUND,
    
    // ADDING other things perhaps later right
    
} serror_t;

void Err_Print( serror_t error_code, const char *fmt, ... );
void Err_Printf( const char *fmt, ... );
void Err_FPrintf( FILE *fstream, const char *fmt, ... );

#endif

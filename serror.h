#ifndef __SERROR_H__
#define __SERROR_H__

#include <errno.h>
#include <stdarg.h>
#include <stdio.h>

#define ERR_PRINTF( ... )           Err_Printf( __VA_ARGS__ )
#define ERR_FPRINF( stream, ... )   Err_FPrintf( stream, __VA_ARGS__ )
#define ERR_PRINT( error, ... )     Err_Print( error, __VA_ARGS__ )

typedef enum {
    
    SERR_NONE = 0,
    SERR_MEMORY, 
    SERR_FORK,
    SERR_EXEC,
    SERR_CMD_NOT_FOUND,
    
    // ADDING other things perhaps later right
    
} serror_t;

static const char *serror_strings[] = {
    "no error",
    "memory allocation failed",
    "fork failed",
    "exec failed",
    "command not found"
};

void Err_Print( serror_t error_code, const char *fmt, ... );
void Err_Printf( const char *fmt, ... );
void Err_FPrintf( FILE *fstream, const char *fmt, ... );

#endif          /* __SERROR_H__ END */

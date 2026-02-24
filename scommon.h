#ifndef __S_COMMON_H__
#define __S_COMMON_H__ 

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/wait.h>

#define PROMPT                          "$ "
#define SHELL_NAME                      "simpleshell"

#define MAX_ARGS                        64
#define MAX_LINE_INPUT                  4096
#define DELIMITERS                      " \t\n"

#define COM_PRINTF( ... )               Com_Printf( __VA_ARGS__ )
#define COM_FPRINTF( stream, ... )      Com_FPrintf( stream, __VA_ARGS__) 

typedef uint8_t         byte;
typedef uint16_t        u16;
typedef uint32_t        u32;
typedef uint64_t        u64;
typedef byte            sbool;

typedef int8_t          i8;
typedef int16_t         i16;
typedef int32_t         i32;
typedef int64_t         i64;

typedef struct {
    char *tokens[MAX_ARGS];
    u32 token_count;
} s_cmd_t;

void Com_Printf( const char *fmt, ... );
void Com_FPrintf( FILE *fstream, const char *fmt, ... );

#endif          /* __S_COMMON_H__ END */

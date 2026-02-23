#ifndef __S_COMMON_H__
#define __S_COMMON_H__ 

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define PROMPT          "$ "
#define SHELL_NAME      "simpleshell"

#define MAX_ARGS        64
#define MAX_LINE_INPUT  2048
#define DELIMITERS      " \t\n"

typedef uint8_t         byte;
typedef uint16_t        u16;
typedef uint32_t        u32;
typedef uint64_t        u64;
typedef byte            sbool;

typedef int8_t          i8;
typedef int16_t         i16;
typedef int32_t         i32;
typedef int64_t         i64;

#endif          /* __S_COMMON_H__ END */

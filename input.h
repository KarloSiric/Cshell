#ifndef __S_INPUT_H__
#define __S_INPUT_H__ 

#include "scommon.h"

typedef enum {
    BUILTIN_NONE = 0,
    BUILTIN_CD,
    BUILTIN_EXIT,
    // BUILTIN_PWD,
    // BUILTIN_ECHO,
} s_builtin_t;

int Input_Parse( char *line, s_cmd_t *cmd );
s_builtin_t Input_Builtin( s_cmd_t *cmd );
void Input_Run_Builtin( s_cmd_t *cmd, s_builtin_t type );

#endif          /* __S_INPUT_H__ END */

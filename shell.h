#ifndef __SHELL_H__
#define __SHELL_H__ 

#include "scommon.h"

void Shell_Init();
void Shell_Exit();
void Shell_Loop();
void Shell_Prompt();
void Shell_Parse( const char *line );
void Shell_Execute( s_cmd_t *cmd );
char *Shell_Readline();


#endif              /* __SHELL_H__ END */

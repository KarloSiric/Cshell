#ifndef __SHELL_H__
#define __SHELL_H__ 

#include "scommon.h"
#include "serror.h"

void Shell_Init();
void Shell_Loop();
void Shell_Prompt();
void Shell_Readline( const char *buf, size_t bufsize );








#endif

/*======================================================================
   File: main.c
   Project: shell
   Author: ksiric <email@example.com>
   Created: 2026-02-24 01:38:31
   Last Modified by: ksiric
   Last Modified: 2026-02-24 20:24:36
   ---------------------------------------------------------------------
   Description:

   ---------------------------------------------------------------------
   License:
   Company:
   Version: 0.1.0
 ======================================================================
																	   */
#include "shell.h"

int main( int argc, char const *argv[] ) {
	(void)argc;
	(void)argv;

	Shell_Init();
	Shell_Loop();

	return 0;
}

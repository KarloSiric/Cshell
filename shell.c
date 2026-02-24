/*======================================================================
   File: shell.c
   Project: shell
   Author: karlosiric <email@example.com>
   Created: 2026-02-23 15:01:23
   Last Modified by: ksiric
   Last Modified: 2026-02-24 12:43:30
   ---------------------------------------------------------------------
   Description:
       
   ---------------------------------------------------------------------
   License: 
   Company: 
   Version: 0.1.0
 ======================================================================
                                                                       */


#include "shell.h"
#include "input.h"
#include "serror.h"

static s_cmd_t *cmd = NULL;

void Shell_Init( void ) {
    
    COM_PRINTF( "Welcome to %s\n", SHELL_NAME );
    COM_PRINTF( "Type 'exit' to quit.\n" );   
    
    return ;
}

void Shell_Prompt( void ) {
    
    COM_FPRINTF( stdout, "%s: $ ", SHELL_NAME );
    
    return ;
}

/* Helper function for checking if the shell should exit or not */

int ShellShouldExit( char *cmd ) {
    while ( *cmd == ' ' || *cmd == '\t' || *cmd == '\n' ) {
        cmd++;
    }
    
    // checking if the string is empty or not
    if ( *cmd == '\0' ) {
        return ( 0 );
    }
    
    char *end = cmd + strlen( cmd ) - 1;
    
    while ( (end > cmd ) && ( *end == ' ' || *end == '\t' || *end == '\n' ) ) {
        *end = '\0';        // we set the characters to the NULL terminating char
        end--;
    }
        
    if ( strcmp( cmd, "exit" ) == 0 ){
        return ( 1 );
    }
    else if ( strcmp( cmd, "quit" ) == 0 ){
        return ( 1 );
    }
    
    return ( 0 );
}

char *Shell_Readline( void ) {
    
    char *line = NULL;
    size_t linelen = 0;
    
    if ( getline( &line, &linelen, stdin ) == -1 ) {
        return NULL;
    }
    
    return line;
}

void Shell_Execute( s_cmd_t *cmd ) {
    
    pid_t pid = fork();             // make a child process inside parent shell!
    
    if ( pid == 0 ) {
        execvp( cmd->tokens[0], cmd->tokens );   
        ERR_PRINT( SERR_EXEC, "%s: Command not found\n", cmd->tokens[0] );
        exit( 1 );
    }
    else if ( pid > 0 ) {
        int *status = NULL;
        waitpid( pid, status, 0 );
    }
    else {
        ERR_PRINT( SERR_FORK, "fork failed\n" );
    }
}

void Shell_Loop( void ) {
    
    char *line_buffer = NULL;
        
    while ( 1 ) {
        
        Shell_Prompt();
        Shell_Readline();
        
        if ( ShellShouldExit( line_buffer ) ) {
            break;
        }
         
         Input_Parse( line_buffer, cmd );
         Shell_Execute( cmd );
    }
    
    return ;
}


/*======================================================================
   File: input.c
   Project: shell
   Author: ksiric <email@example.com>
   Created: 2026-02-24 12:16:31
   Last Modified by: ksiric
   Last Modified: 2026-02-24 19:32:33
   ---------------------------------------------------------------------
   Description:
       
   ---------------------------------------------------------------------
   License: 
   Company: 
   Version: 0.1.0
 ======================================================================
                                                                       */

#include "input.h"
#include "serror.h"
#include "shell.h"

int Input_Parse( char *line, s_cmd_t *cmd ) {
    cmd->token_count = 0;
    
    char *token = strtok( line, DELIMITERS );
    
    while ( token != NULL && cmd->token_count < MAX_ARGS - 1 ) {
        
        cmd->tokens[cmd->token_count] = token;
        cmd->token_count++;
        token = strtok( NULL, DELIMITERS );
    }
    
    cmd->tokens[cmd->token_count] = NULL;
    
    return ( cmd->token_count );
}

s_builtin_t Input_Builtin( s_cmd_t *cmd ) {
    if ( cmd->token_count == 0 ) {  
        return ( BUILTIN_NONE );
    }
    
    if ( strcmp( cmd->tokens[0], "cd" ) == 0 ) {
        return ( BUILTIN_CD ); 
    }
    
    if ( strcmp( cmd->tokens[0], "exit" ) == 0 ) {
        return ( BUILTIN_EXIT ); 
    }
    
    return ( 0 );
    
}

void Input_Run_Builtin( s_cmd_t *cmd, s_builtin_t type ) {
    switch( type ) {
        case BUILTIN_NONE: 
        {
            return;
            break;
        }
        case BUILTIN_CD: 
        {
            // TODO(KARLO): Handle the cd command
            if ( cmd->tokens[1] == NULL ) {
                char *home = getenv("HOME");
                if ( home == NULL ) {
                    ERR_PRINTF( "cd: HOME not set\n" );
                } 
                else {
                    chdir( home );
                }
            } 
            else {
                if ( chdir( cmd->tokens[1] ) != 0 ) {
                    ERR_PRINTF( "cd: %s: No such file or directory\n", cmd->tokens[1] );       
                }
            }
            break;
        }
        case BUILTIN_EXIT: 
        {
            // TODO(KARLO): handling the exit and leaving the shell 
            Shell_Exit();
        }
        
        default:
            break;
    }
}

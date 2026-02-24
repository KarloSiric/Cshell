/*======================================================================
   File: input.c
   Project: shell
   Author: ksiric <email@example.com>
   Created: 2026-02-24 12:16:31
   Last Modified by: ksiric
   Last Modified: 2026-02-24 12:29:39
   ---------------------------------------------------------------------
   Description:
       
   ---------------------------------------------------------------------
   License: 
   Company: 
   Version: 0.1.0
 ======================================================================
                                                                       */

#include "input.h"

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



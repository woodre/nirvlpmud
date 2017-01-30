/*
 *      File:                   /players/earwax/guild_base/daemons/commandsd.c
 *      Function:               Load, update, setup commands centrally
 *      Author(s):              Earwax@Nirvana
 *      Copyright:              Copyright (c) 2005 Earwax
 *                                      All Rights Reserved.
 *      Source:                 05/24/2004
 *      Notes:                  
 *      Change History:
 */

#include <ansi.h>
#include <security.h>
#include "../defs.h"

/* Global Variables */
int     Size, 
       *Levels;   
string *Commands; 

/* 
 * Function name:  load_commands
 * Description:    Get the list of commands by reading bin directory
 * Arguments:      none
 * Returns:        void
 */

void
load_commands()
{
int i;
string *t;

i = Size = sizeof(t = get_dir(BIN+"*.c"));
Levels = allocate(Size); Commands = allocate(Size);

while(i--)
{
  if (sscanf(t[i], "%s.%d.c", Commands[i], Levels[i]) != 2)
  {
  sscanf(t[i], "%s.c", Commands[i]);
  Levels[i] = 0;
  }
  }
}

 /* 
 * Function name:  get_commands
 * Description:    Get the valid commands for certain guild level
 * Arguments:      int glevel - guild level to check against
 * Returns:        string*    - a string array of all valid commands
 */

string
*get_commands(int glevel)
{
int i;
string *t;

i = Size; t = ({ });

while(i--)
  if (Levels[i] <= glevel)
    t += ({ Commands[i] });
}


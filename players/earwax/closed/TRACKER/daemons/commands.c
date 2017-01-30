/* *************************************************************************
 * /players/earwax/closed/TRACKER/daemons/commands.c
 *
 * Commands Daemon
 *
 * Earwax 7/28/03
 *
 * Controls usable commands.
 *
 * *************************************************************************
 *
 * Called by init() in the tracker object, it returns an array of the
 * usable commands
 *
 * *************************************************************************
*/

#include "../defs.h"

inherit WAXFUNS;

/* Global Variables */
string *Allcommands;     /* Mapping of all usable commands */

/* Prototype Declarations */
void load_commands();

/* *************************************************************************
 * reset
 *
 * I like to keep this first, so that's why there's a prototype declaration
*/

void
reset(status arg)
{
  if (arg)
    return;

  load_commands();
tell_object(find_player("earwax"),"loaded...size is: "+sizeof(Allcommands)+"\n");
}

/* *************************************************************************
 * load_commands
 *
 * load the available commands.  Figure out what's in the bin dir, and load
 * them into an array, Allcommands.
*/

status
load_commands()
{
  int i;

  i = sizeof(Allcommands = get_dir(BINDIR + "*.c"));

  while(i--) sscanf(Allcommands[i],"%s\.c",Allcommands[i]);
}

/* *************************************************************************
 * return_commands
 *
 * return the array of commands.  This is a really complex function.
*/

string
*return_commands()
{
  return Allcommands;
}

/* *************************************************************************
 * rehash_commands
 *
 * reload the array of commands basically.
 * Returns int for error checking purposes basically.
*/

int
rehash_commands()
{
  load_commands();
  return sizeof(Allcommands);
}

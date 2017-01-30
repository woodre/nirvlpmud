/* *************************************************************************
 * Commands Daemon
 *
 * - Earwax 9/03
 *
 * *************************************************************************
*/

#include "../defs.h"

string *Commands;

void rehash() {
  string *t; int i;

  i = sizeof(Commands = get_dir(BINDIR+ "*.c"));
  while (i--) sscanf(Commands[i],"%s.c",Commands[i]);
}

void reset(status arg) { if (!arg) rehash(); }
 
string *get_commands() { return Commands; }

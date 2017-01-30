#include "defs.h"
inherit "/players/earwax/closed/sefun.c";

/* Globals */
string *cmdlist;

/* Prototypes */
int initialize_commands();

void reset(status arg) {
  if (arg)
    return;

  initialize_commands();
}

int initialize_commands() {
  object wax;

  wax = find_player("earwax");
  if (!wax) {
    cmdlist = ({ });
    return 1;
  }

  cmdlist = query_actions(wax);
  tell_object(wax,"SIZE is: "+sizeof(cmdlist)+"\n");
  return 1;
}

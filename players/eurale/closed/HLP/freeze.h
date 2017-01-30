#include "DEF.h"

freeze(str) {
  if(!str) { write("Usage:  freeze <who>\n"); return 1; }
  if(!find_player(str)) { write("Not logged on....\n"); return 1; }
  tell_object(find_player(str),
    HIC+"You feel yourself freeze solid....\n"+NORM);
  move_object(clone_object("players/eurale/closed/shut_up.c"),
    find_player(str));
  write(HIC+capitalize(str)+" is frozen...... bliss!\n"+NORM);
return 1;
}

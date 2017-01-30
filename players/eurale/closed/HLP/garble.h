#include "DEF.h"
 
garble(str) {
  if(!str) { write("garble <who> \n"); return 1; }
  if(!find_player(str)) { write("Not logged on.... \n"); return 1; }
  move_object(clone_object("players/eurale/closed/garble.c"),
	find_player(str));
  command("save",find_player(str));
  write(capitalize(str)+" has been GARBLED....\n");
return 1;
}

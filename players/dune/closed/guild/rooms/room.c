inherit "room/room";
/* Standard Cyber guild room */

#include "../DEFS.h"


CN_PK() { return 1; }
realm() { return "NT"; }
feel() { return "no"; }
CNGuild() { return 1; }

init() {
  TP->set_fight_area();
  ::init();
}

exit() { if(this_player()) this_player()->clear_fight_area(); }

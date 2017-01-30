
/* arena inherit file */

inherit "/room/room";
#include "/players/fred/closed/bloodfist/defs.h"

void reset(mixed arg){
  if(arg) return;

  add_property("no_teleport");
}

void init(){
  ::init();
  ARENA_DAEMON->person(this_player(), 2);
}

void exit(mixed who){
  if(who->is_player())
    ARENA_DAEMON->person(who, 1);
}


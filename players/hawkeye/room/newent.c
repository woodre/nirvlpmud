#include "room.h"

object arm;

#undef EXTRA_RESET
#define EXTRA_RESET\
              extra_reset();

    extra_reset() {
  if (!arm || (!present("private"))) {
    int i;
    while (i<8) {
      i++;
    arm = clone_object("players/hawkeye/monster/private.c");
      transfer(arm, this_object());
    }
  }
}
THREE_EXIT("players/hawkeye/room/entrance.c", "leave",
       "players/hawkeye/room/newbie2.c", "east",
     "players/hawkeye/room/newentd.c", "down",
       "Privates Room",
       "This is a newbie room where newbies can come\n"+
       "to build up xp and money\n",1)

init() {
  ::init();
  if(this_player())
  if(this_player()->id("sapper") && this_player()->query_npc())
    move_object(this_player(), "/players/hawkeye/room/entrance.c");
}

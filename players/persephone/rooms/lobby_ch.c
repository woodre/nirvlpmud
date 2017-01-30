inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset (arg){
  if(!present("guest")){
    move_object(clone_object("players/persephone/monster/guester"), TOB);
  }
 if (!arg) {
  set_light(1);
  short_desc="Chelsea Lobby";
  long_desc="You are in the lobby of the famed Chelsea Hotel to the North you see\n" +
            "the Reception desk and to the East you see the bell hop's station. The\n" +
            "Lobby itself seems to be fairly empty however there is an old man\n" +
            "sitting in one of the large chairs reading a paper.\n" +
             "\n";
  dest_dir=({"players/persephone/rooms/rec_de","north",
              "players/persephone/rooms/bellho","east",
             "players/persephone/rooms/road3b","out",
  });
 }
}
realm() { return "NT"; }

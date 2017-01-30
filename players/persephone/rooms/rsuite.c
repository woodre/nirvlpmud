inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(arg){
  if(!present("thug")){
    move_object(clone_object("players/persephone/monster/thug"), TOB);
    move_object(clone_object("players/persephone/monster/thug"), TOB);
  }
 if (!arg) {
  set_light(0);
  short_desc="Royal Suite";
  long_desc="You are standing in the entrance to the royal suite of Chelsea Hotel\n" +
            "and to call this room large would be an understatement. This room is\n" +
            "more than large it is enormous and also beutifully furnished even here\n" +
            "To the north you see the ballroom and to the south is the royal suite.\n" +
            "\n";
  dest_dir=({"players/persephone/rooms/roy_bal","north",
             "players/persephone/rooms/ro_sui","south",
             "players/persephone/rooms/hcorr3b","west",
            });
 }
}
realm() { return "NT"; }

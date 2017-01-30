inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(arg){
 if (!arg) {
  set_light(1);
  short_desc="Security Room";
  long_desc="This is the room that security officers stay in when a foreign dignatory\n" +
            "stays at the hotel. On the south wall next to the exit to the corridor\n" +
            "you see a large gunrack. The rest of the room is actually quite spartan\n" +
            "and there are absolutely no beds in this room or other furniture except\n" +
            "for some chairs.\n" +
            "\n";
  dest_dir=({"players/persephone/rooms/hcorr2b","south",
           });
 }
}
realm() { return "NT"; }

inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(arg){
 if(!arg) {
  set_light(1);
  short_desc="Third Floor";
  long_desc="This corridor surpasses those of the other levels in this exclusive\n" +
            "international hotel. To the north you see the stairs leading down while\n" +
           "the corridor continues to the east.\n" +
           "\n";
  dest_dir=({"players/persephone/rooms/hotstb.c","north",
            "players/persephone/rooms/hcorr3b.c","east",
           });
 }
}
realm(){ return "NT"; }

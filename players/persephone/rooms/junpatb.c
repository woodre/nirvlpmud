inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(arg){
 if (arg) return;
  set_light(0);
  short_desc="Jungle Path";
  long_desc="You feel a deep sense of forboding as you enter the jungle there is\n" +
            "sounds coming from all around. To the east the path is even narrower\n" +
            "and just looking in that direction sends a shiver down your back.\n" +
            "\n";
  dest_dir=({"players/persephone/rooms/junpata","west",
             "players/persephone/rooms/junpatc","east",
            });
}

inherit "/players/persephone/closed/thingys";
#include "/players/persephone/rooms.h"
reset(arg){
if (!arg) {
  set_light(1);
  short_desc="Staircase Landing";
  long_desc="You are on the first floor landing of the Chelsea Hotel the stairs.\n" +
            "continue up and down while there is a passage just south of here. The\n" +
            "light appears to be adequate however further up it appears to get much \n" +
             "darker.\n" +
            "\n";

  dest_dir=({"players/persephone/rooms/hcorr1a","south",
             "players/persephone/rooms/hotsta","up",
             "players/persephone/rooms/rec_de","down",
  });
 }
}
realm() { return "NT"; }

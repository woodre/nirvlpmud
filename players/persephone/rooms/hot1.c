inherit "/players/persephone/closed/thingys";
#include "/players/persephone/rooms.h"
reset(arg){
if (!arg) {
  set_light(1);
  short_desc="Dingy Hotel";
  long_desc="You are in the lobby of a dingy hotel, flop house, might be a better\n" +
            "description. There is a set of stairs straight to the south and what\n" +
           "appear to be bodies lying on the floor with dark looking figures \n" +
           "carrying more down the stairs.\n" +
           "\n";
  dest_dir=({"players/persephone/rooms/stairsa1","up",
             "players/persephone/rooms/road2b","out"
  });
 }
}

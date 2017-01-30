inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(arg){
 if(!present("worker")){
  move_object(clone_object("players/persephone/monster/worker"),TOB);
 }
 if(!arg) {
  set_light(1);
short_desc="End of Wharf";
  long_desc="You have reached the end of the first wharf in the harbour. Docked\n" +
            "along side the wharf here is a large boat and you see many people\n" +
            "walking up and down gangplanks carrying heavy loads of fruit that\n" +
            "appear to be bananas. Back to the Southwest the pier continues towards\n" +
           "the harbour\n";
  dest_dir=({"players/persephone/rooms/pier1a","southwest",
            "players/persephone/rooms/boat1a","board"
  });
 }
}
realm() { return "NT"; }

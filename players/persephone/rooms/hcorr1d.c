inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(arg){
 if (!arg) {
  set_light(1);
  short_desc="Chelsea Corridor";
  long_desc="You are on the first floor corridor of the Chelsea Hotel. The corridor\n" +
            "continues to the east while there are rooms to the north and south.\n" +
            "Directly to your west is a wall while above the room entrances are\n" +
            "large numbers however it appears that the doors are missing.\n" +
            "\n";
  items=({"walls","The walls are painted in soothing shades of blue and have borders",
          "borders","Strange that the borders should be red however there are strange\n" +
                    "patterns in them",
          "patterns","The patterns appear to be of Dragons",
          "doors","There are no doors, they seem to have been removed",
          "corridor","It seems to look the same in both directions however you can\n" +
          "see the end of the corridor is closer to the west",
          "number","These are just room numbers. The one to the south is 112 and the\n" +
                   "one to the north is 111 definately not your rooms",
          "rooms","You can not really tell what the rooms look like you will have\n" +
                 "to enter them if you are interested",
          });
  dest_dir=({"players/persephone/rooms/hcorr1c","east",
  });
 }
}
realm(){ return "NT"; }

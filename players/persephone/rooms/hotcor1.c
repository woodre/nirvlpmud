inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(arg){
  if(!present("pirate")){
    move_object(clone_object("players/persephone/monster/piradh"),TOB);
    move_object(clone_object("players/persephone/monster/piradh"),TOB);
  }
 if (!arg) {
  set_light(1);
  short_desc="Chelsea Corridor";
  long_desc="You are on the first floor corridor of the Chelsea Hotel. The corridor\n" +
            "continues both to the east and the west and there are rooms north and\n" +
            "south. On top of the entrance to each room is a number however it looks\n" +
            "like the doors that would have been either wall are now missing.\n" +
            "\n";
  items=({"walls","The walls are painted in soothing shades of blue and have borders",
          "borders","Strange that the borders should be red however there are strange\n" +
                    "patterns in them",
          "patterns","The patterns appear to be of Dragons",
          "doors","There are no doors, they seem to have been removed",
          "corridor","It seems to look the same in both directions however you can\n" +
          "see the end of the corridor is closer to the east",
          "number","These are just room numbers. The one to the south is 106 and the\n" +
                   "one to the north is 105 definately not your rooms",
          "rooms","You can not really tell what the rooms look like you will have\n" +
                 "enter them if you are interested",
          });
  dest_dir=({"players/persephone/rooms/rm105","north",
            "players/persephone/rooms/hcorr1a","west",
             "players/persephone/rooms/rm106","south",
             "players/persephone/rooms/hotcor1a","east",
  });
 }
}
realm(){ return "NT"; }

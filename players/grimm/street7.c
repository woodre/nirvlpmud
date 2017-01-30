#include "/players/grimm/header"
inherit "room/room";

reset(arg) {
  if (arg) return;
  short_desc="Old Street";
  long_desc="You are in the town circle.  You can see a shop in the northwest\n"+
         "direction and the way back to the entrance of the circle is to\n"+
   	 "the southwest.  You see a clock tower to the west of you but there\n"+
         "doesn't seen to be any entrances from here.  There is also a long\n"+
         "path leading south into what appears to be a forest.  A hardware\n"+
        "store is to the east.\n";
  dest_dir=({ROOT(street8),"southwest",
          ROOT(street11),"north",
           DIR6(forest30),"south",
          ROOT(hardware),"east",
          ROOT(street6),"northwest"});
  set_light(0);
}

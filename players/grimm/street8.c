#include "/players/grimm/header"
inherit "room/room";

reset(arg) {
  if (arg) return;

  short_desc="Old Street";
  long_desc="You are in the town circle.  You can see a shop to the north from\n"+
         "here.  The way back to the entrance of the circle is to the west\n"+
         "or you can continue walking around the circle to the northeast.\n"+
         "You can see a clock tower to the northwest, but there don't seem\n"+
       "to be any entrances from here.  There is also a kennel to the south.\n";
  dest_dir=({ROOT(street7),"northeast",
          DIR6(forest30),"east",
          ROOT(street9),"west",
          ROOT(kennel),"south"});
  set_light(0);
}

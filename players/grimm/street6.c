#include "/players/grimm/header"
inherit "room/room";
reset(arg) {
  if(arg) return;

  short_desc="Old Street";
  long_desc="You are in the town circle.  The way back to the entrance of\n"+
  "the circle is to the west or you can continue walking around the circle\n"+
  "to the southeast.  You can see a clock tower to the southwest, but there\n"+
  "doesn't seem to be any entrances to it from here.\n";
  dest_dir=({ROOT(street7),"southeast",
/*
            ROOT(shop),"north",
*/
            ROOT(street5),"west",
            ROOT(street11),"east"});
  set_light(0);
}

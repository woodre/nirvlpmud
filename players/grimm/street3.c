#include "/players/grimm/header"
inherit "room/room";

reset (arg) {
  if (arg) return;
  short_desc="Sacred Blood";
  long_desc="You are in the town circle.  You can go either southeast or\n"
     +"northeast to walk around the circle.  You can see a great clock\n"
     + "tower to the east of you, but there doesn't seem to be any\n"
     + "entrance from this side of the circle.\n";
  dest_dir=({ROOT(street2),"west",
             ROOT(street10),"south",
             ROOT(street9),"southeast",
             ROOT(street5),"northeast"});
  set_light(0);
}

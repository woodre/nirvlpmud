#include "/players/grimm/header"
inherit "room/room";

reset (arg) {
  if (arg) return;
  short_desc="Old Street";
  long_desc="You have entered the town of Sacred Blood.  By the look of\n"+
      "all the shops and houses this was a very busy town, but there don't\n"+
      "seem to be any people on the streets any longer.\n";
  dest_dir=({ROOT(street2),"east",
              "players/grimm/frst/path1","west",
             DIR6(forest1),"south"});
  set_light(0);
}

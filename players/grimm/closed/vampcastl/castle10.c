#include "/players/grimm/header"
inherit "room/room";
realm() { return "NT"; }
reset(arg) {
  if(arg) return;

  short_desc="Small Hallway";
  long_desc="This is a smaller hallway that continues to the south leading\n"+
            "into a stairwell.\n";
  dest_dir=({DIR5(castle6),"north",
             DIR5(castle13),"south"});
  set_light(1);
}

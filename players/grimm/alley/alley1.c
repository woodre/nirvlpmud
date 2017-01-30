#include "/players/grimm/header"
inherit "room/room";

reset(arg) {
  if(arg) return;
short_desc="Dark Alley";
long_desc="This is a dark and dreary alley.  You seem to see a figure in the\n"
       + "distance to the east.\n";
dest_dir=({ROOT(alley2), "east",
         "room/pub2","west"});
set_light(1);
}

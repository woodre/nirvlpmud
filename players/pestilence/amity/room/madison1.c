#include "/players/pestilence/ansi.h"
#define TP this_player()
inherit "/players/vertebraker/closed/std/room";

reset(arg) {
  if(arg) return;

short_desc = ""+BLU+"Madison Street"+NORM+"";
long_desc =
  "    The street starts to incline here, leading up a hill.  The street\n"+
  "has a few potholes but otherwise is well paved.  There are houses on\n"+
  "each side of the road.  The street runs back to Main Street to the\n"+
  "west and to the east leads further up the hill.  There has been some\n"+
  "sort of struggle here.  The grass in the lawns have been torn up and\n"+
  "there are streaks of blood on the street and grass.\n";
set_light(1);

items = ({
"street","A paved street with curbs on each side leading to the east and west directions",
"houses","A few large white houses on each side of the street",
"hill","A large hill where Madison Street extends to",
"potholes","A few large pot holes about three inches deep into the pavement",
"streaks","Blood splattered on the street and lawns",
"grass","Green grass that has been torn up",
"lawns","Green grass that has been torn up",
"blood","Blood splattered through out the street and lawns",
});

dest_dir = ({
  "/players/pestilence/amity/room/nmain2.c","west",
  "/players/pestilence/amity/room/madhouse2.c","south",
  "/players/pestilence/amity/room/madhouse1.c","north",
  "/players/pestilence/amity/room/madison2.c","east",
});
}

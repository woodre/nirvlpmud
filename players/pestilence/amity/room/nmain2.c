#include "/open/ansi.h"
#define TP this_player()
inherit "/players/vertebraker/closed/std/room";

reset(arg) {
  if(arg) return;

short_desc = ""+BLU+"Corner of Main and Madison"+NORM+"";
long_desc =
  "    This is the intersection of two streets.  Both streets are well\n"+
  "paved.  North Main continues to the north and south, while Madison\n"+
  "heads east.  There are businesses on either side of North Main street.\n"+
  "Madison Street has houses on each side of the street.  The street\n"+
  "appears to have some blood drops leading towards Madison.\n";
set_light(1);

items = ({
"businesses","Some shops and other assorted businesses are located on each side of the street",
"street","A well paved street the the main part of town",
"houses","There are houses on each side of Madison Street",
"shops","A normal shop to the west and a few more to the northeast and northwest",
"intersection","This is where North Main Street and Madison Street cross each other",
"blood","Some blood drops leading towards Madison Street",
"blood drops","Some blood drops leading towards Madison Street",
"drops","Some blood drops leading towards Madison Street",
"streets","Well paved streets running through the main part of town",
});

dest_dir = ({
  "/players/pestilence/amity/room/nmain1.c","south",
  "/players/pestilence/amity/room/nmain3.c","north",
  "/players/pestilence/amity/room/shop.c","west",
  "/players/pestilence/amity/room/madison1.c","east",
});
}

#include "/open/ansi.h"
#define TP this_player()
inherit "/players/vertebraker/closed/std/room";

reset(arg) {
  if(arg) return;

if (!present("ant")) {
  move_object(clone_object("/players/pestilence/amity/mob/guard.c"),
        this_object()); }

short_desc = ""+YEL+"Dirt Path"+NORM+"";
long_desc =
  "    This is a well worn dirt path.  All the ants travel through\n"+
  "this path to get to the only entrance to the mound.  To the north\n"+
  "there is a hole in the large mound of dirt.  Something doesn't\n"+
  "seem right about this place.  There is a large pool of blood and\n"+
  "body parts laying in the middle of the path.  To the south you\n"+
  "can see Madison Street.\n";
set_light(1);

items = ({
"hole","A large hole in the mound to the north",
"blood","A pool of blood laying in the path",
"large pool","A pool of blood laying in the path",
"blood spots","A pool of blood laying in the path",
"spots","A pool of blood laying in the path",
"path","A worn path caused by bodies being dragged through here",
"pool","A pool of blood laying in the path",
"parts","Various body parts from a human body",
"body parts","Various body parts from a human body",
"dirt","Normal brown dirt",
"street","Madison Street can be seen to the south",
"mound","A large mound of dirt to the north of here",
"madison street","Madison Street can be seen to the south",
});

dest_dir = ({
  "/players/pestilence/amity/room/madison2.c","south",
  "/players/pestilence/amity/room/mound.c","north",
});
}

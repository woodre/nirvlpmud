#include "/players/pestilence/ansi.h"
#define TP this_player()
inherit "room/room";

reset(arg) {
  if(arg) return;


if (!present("cannibal")) {
  move_object(clone_object("/players/pestilence/Cahara/mob/cannibal.c"),
        this_object()); }
short_desc = ""+YEL+"Cahara Island Hut"+NORM+"";
long_desc =
  "    This is one of the larger huts.  The walls are made of mud, the floor\n"+
  "consists of dirt, and the ceiling is made from tall grass.  There are three\n"+
  "rooms in this hut.  This is the main room.  It is larger than the other two.\n"+
  "There is a fireplace on the east wall.  A large stone table fills the middle.\n"+
  "of the room.  The other two rooms are to the north and south.\n";
set_light(1);

items = ({

});

dest_dir = ({
  "/players/pestilence/Cahara/room/enhut.c","north",
  "/players/pestilence/Cahara/room/eshut.c","south",
  "/players/pestilence/Cahara/room/nwvillage.c","west",
});

}

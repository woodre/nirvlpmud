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
  "    This is a normal mud hut.  The walls are made entirely of mud, with\n"+
  "no windows.  The floor is a dirt floor, the roof is made from plants\n"+
  "and other shrubbery.  It consists of one large room.  There is a small\n"+
  "stone table near the north wall, with a fireplace built into the north wall.\n"+
  "On the west side of the room, there is an area that is made up for three people.\n"+
  "to sleep\n";
set_light(1);

items = ({

});

dest_dir = ({
  "/players/pestilence/Cahara/room/nwvillage.c","east",
});

}

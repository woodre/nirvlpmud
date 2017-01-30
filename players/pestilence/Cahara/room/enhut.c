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
  "    A small room in the northern part of the hut.  This is the room where the\n"+
  "inhabitants of this dwelling sleep.  There are blankets made from animal skins\n"+
  "on the floor.  Also there is a small fireplace on the north wall, to provide heat.\n"+
  "curing the cold nights.\n";
set_light(1);

items = ({

});

dest_dir = ({
  "/players/pestilence/Cahara/room/ehut.c","south",
});

}

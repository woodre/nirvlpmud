#include "/players/pestilence/ansi.h"
#define TP this_player()
inherit "room/room";

reset(arg) {
  if(arg) return;

if (!present("cannibal")) {
  move_object(clone_object("/players/pestilence/Cahara/mob/cannibal.c"),
        this_object()); }

short_desc = ""+YEL+"Cahara Island Village"+NORM+"";
long_desc =
  "    This is an entrance to a small village.  To the north is the center of \n"+
  "the village.  Small huts suroound the area to the east, west and south.  The path\n"+
  "leads back to the southeast.  A fence made from small trees, encompass the\n"+
  "village.\n";
set_light(1);

items = ({

});

dest_dir = ({
  "/players/pestilence/Cahara/room/ehut.c","east",
  "/players/pestilence/Cahara/room/cvillage.c","north",
  "/players/pestilence/Cahara/room/whut.c","west",
  "/players/pestilence/Cahara/room/path.c","southeast",
});

}

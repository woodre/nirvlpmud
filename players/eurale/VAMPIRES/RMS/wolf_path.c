inherit "room/room";
#include "check.h"
#include "/players/eurale/defs.h"

reset(arg) {
if(!present("yakker")) {
  move_object(clone_object("players/eurale/VAMPIRES/NPC/wolf_howl.c"),
    this_object()); }
  if(arg) return;
set_light(0);

short_desc = "Dark path";
long_desc =
  "This narrow path continues both east and west.  Off to the east you\n"+
  "can just make out the lights of the vampire shop.  To the west is a\n"+
  "dense forest with large trees.  The path is well worn which would\n"+
  "indicate many feet have traveled this way.\n";

items = ({
  "path","A narrow dirt trail worn through the foliage of this thick,\n"+
         "and forboding forest",
  "shop","The lights filter through the narrow windows of the vampire\n"+
         "shop",
  "forest","Many, large and strange trees... they almost appear to be "+
           "moving...",
  "trees","Dark, with thick leaves and rough bark",
});

dest_dir = ({
  "players/eurale/VAMPIRES/RMS/shop.c","east",
  "players/eurale/VAMPIRES/RMS/wolf_summon.c","west",
});

}

realm() { return "NT"; }

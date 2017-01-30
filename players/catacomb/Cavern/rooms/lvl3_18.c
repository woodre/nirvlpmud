#include "/players/catacomb/misc/ansi.h"
#define TP this_player()
#define TPN this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc =("Durkor Caverns");
long_desc =(
"  The cavern ends with a large rock wall.  The ceiling lies several\n"+
"yards above.  Small rays of light filter down through the cracks in\n"+
"the roof of the cavern.  The floor slopes slightly down to the west\n"+
"of the cavern floor.\n");

if(!present("spider"))
	  move_object(clone_object("/players/catacomb/Cavern/mobs/Gspider.c"),
	    this_object());

items = ({
  "ceiling",
  "The cracks in the ceiling provide light to the cavern", 
  "cracks",
  "The cracks in the ceiling provide light to the cavern", 
  "rays",
  "The cracks in the ceiling provide light to the cavern",
  "floor",
  "The floor slopes down to the west",
  "ground",
  "The floor slopes down to the west",
  });

dest_dir = ({
  "/players/catacomb/Cavern/rooms/lvl3_17.c","southwest",
  "/players/catacomb/Cavern/rooms/lvl3_19.c","northwest",
  "/players/catacomb/Cavern/rooms/lvl3_20.c","west" 
});
}


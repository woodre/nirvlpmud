#include "/players/catacomb/misc/ansi.h"
#define TP this_player()
#define TPN this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc =("Durkor Caverns");
long_desc =(
"  The ceiling towers several yards above.  Small rays of light can be seen\n"+
"entering through cracks in the ceiling.  The area opens up to the east and \n"+
"constricts to the west.  Torches can be seen on the western walls.  The ground\n"+
"seems to slope very slightly to the east.\n");

if(!present("soulfire"))
	  move_object(clone_object("/players/catacomb/Cavern/mobs/soulFire.c"),
	    this_object());

items = ({
  "ceiling",
  "The ceiling looms very high over top of you", 
  "rays",
  "The rays shine through the cracks in the ceiling", 
  "cracks",
  "The cracks in the ceiling provide light for the cavern",
  "crack",
  "The cracks in the ceiling provide light for the cavern",
  "light",
  "Light shines in from the ceiling",
  "torches",
  "Torches line the passageway to the west",
  "torch",
  "Torches line the passageway to the west",
  "ground",
  "The ground slopes very slightly to the east"
  });

dest_dir = ({
  "/players/catacomb/Cavern/rooms/lvl3_19.c","northeast",
  "/players/catacomb/Cavern/rooms/lvl3_17.c","southeast",
   "/players/catacomb/Cavern/rooms/lvl3_20.c","east", 
  "/players/catacomb/Cavern/rooms/lvl3_15.c","west",
/* added by Daranath - missing exit? */
});
}


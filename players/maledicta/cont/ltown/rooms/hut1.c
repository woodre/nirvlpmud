#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
#include "/players/maledicta/ansi.h"
object civ;
reset(arg) {
if(!present("cont_lizardman", this_object())){
civ = clone_object("/players/maledicta/cont/ltown/mobs/lcivilian.c");
	move_object(civ, this_object());
	}
  if(arg) return;
set_light(1);

short_desc = "a private residence [Terk'ula]";
long_desc =
"  You stand inside a hut made from wood and mud. The walls are\n"+
"very smooth and the floor is slightly muddy. A large pool of\n"+
"water can be found at the rear of the hut. Its waters seem very\n"+
"clear. A small wooden door leads out.\n";

items = ({
  "pool",
  "A large pool of water that sparkles in the available light",
  "water",
  "A clear water toward the back of the hut",
  "walls",
  "Simple mud and wood walls",
  "door", 
  "A small wooden door",
});

dest_dir = ({
  "/players/maledicta/cont/ltown/rooms/l2.c", "out",
});

}


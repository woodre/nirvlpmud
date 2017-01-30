#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
#include "/players/maledicta/ansi.h"
object naga;
reset(arg) {
if(!present("naga", this_object())){
naga = clone_object("/players/maledicta/cont/dragon/mobs/naga.c");
	move_object(naga, this_object()); }
  if(arg) return;
set_light(1);

short_desc = ""+BOLD+"The "+HIB+"Dragons"+NORM+BOLD+" Cave"+NORM+"";
long_desc =
"   Here the cave widens further into a large sub-chamber. A\n"+
"large pit lies in the center. The walls here are smoother\n"+
"than those at the entrance, and almost seem worked. A huge\n"+
"tunnel can be seen to the north and also to the east.\n";

items = ({
  "pit",
  "A huge empty pit filled with ashes",
  "walls",
  "The rock walls surrounding you seem very smooth and probably\n"+
  "worked by professional hands",
  "tunnel",
  "Large tunnels that lead further into the cave",
});

dest_dir = ({
  "/players/maledicta/cont/dragon/rooms/cave3.c","north",
  "/players/maledicta/cont/dragon/rooms/cave4.c","east",
  "/players/maledicta/cont/dragon/rooms/cave1.c","south",
});

}

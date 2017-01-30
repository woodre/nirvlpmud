#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
#include "/players/maledicta/ansi.h"
object dragon;
reset(arg) {
if(!present("cont_dragon", this_object())){
dragon = clone_object("/players/maledicta/cont/dragon/mobs/bdragon1.c");
	move_object(dragon, this_object());
 }
	
  if(arg) return;
set_light(1);

short_desc = ""+BOLD+"The "+HIB+"Dragons"+NORM+BOLD+" Cave"+NORM+"";
long_desc =
"  You have entered a small sub-chamber. The heat here\n"+
"is almost unbearable. A large pit can be found with a\n"+
"roaring fire in it in the center of the room. A small\n"+
"hole allows smoke to escape into the sky above. To the\n"+
"east is a huge archway, and to the west is the tunnel\n"+
"leading back to the entrance. You cannot make out what\n"+
"is to the east through all the smoke.\n"; 

items = ({
  "walls",
  "The walls here are very smooth to the touch, but also\n"+
  "very warm",
  "pit",
  "A huge pit with a roaring fire in the center. It seems to be\n"+
  "the source of all this heat",
  "fire",
  "A huge fire that is held within the boundaries of the pit",
  "hole",
  "A very small hole in the ceiling which allows smoke to\n"+
  "escape freely",
  "smoke",
  "A thick black smoke",
  "ceiling",
  "A smooth red tinted ceiling with a hole in its center",
  "archway",
  "A large round archway which leads to the east",
});

dest_dir = ({
  "/players/maledicta/cont/dragon/rooms/cave4.c","west",
  "/players/maledicta/cont/dragon/rooms/cave8.c","east",
});

}

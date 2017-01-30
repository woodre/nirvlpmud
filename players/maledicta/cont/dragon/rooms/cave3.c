#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
#include "/players/maledicta/ansi.h"
object dragon;

reset(arg) {

if(!present("cont_dragon", this_object())){
dragon = clone_object("/players/maledicta/cont/dragon/mobs/bdragon1.c");
	move_object(dragon, this_object()); }
	
  if(arg) return;
set_light(1);

short_desc = ""+BOLD+"The "+HIB+"Dragons"+NORM+BOLD+" Cave"+NORM+"";
long_desc =
"  This is a very large and long tunnel that leads deep into\n"+
"the hill. The smell of rotting flesh wafts down the tunnel\n"+
"carried on a light breeze. The walls seem very smooth, as\n"+
"well as the floor and ceiling.  The tunnel continues to the\n"+
"north and south.\n";

items = ({
  "ceiling",
  "The ceiling seems to be very smooth with only slight scratches\n"+
  "on its surface",
  "floor",
  "The floor is smooth but has very deep gouges on it",
  "walls",
  "The rock walls surrounding you seem very smooth and probably\n"+
  "worked by professional hands",
});

dest_dir = ({
  "/players/maledicta/cont/dragon/rooms/cave5.c","north",
  "/players/maledicta/cont/dragon/rooms/cave2.c","south",
});

}

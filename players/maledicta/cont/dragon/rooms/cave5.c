#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
#include "/players/maledicta/ansi.h"
object dragon;
object dragon2;
reset(arg) {

if(!present("cont_dragon", this_object())){
dragon = clone_object("/players/maledicta/cont/dragon/mobs/bdragon1.c");
	move_object(dragon, this_object());
dragon2 = clone_object("/players/maledicta/cont/dragon/mobs/bdragon1.c");
	move_object(dragon2, this_object()); }
	
  if(arg) return;
set_light(1);

short_desc = ""+BOLD+"The "+HIB+"Dragons"+NORM+BOLD+" Cave"+NORM+"";
long_desc =
"  Here the cave opens up wide into a large chamber. The walls\n"+
"are decorated in arcane symbols that seem to glow with a dim\n"+
"green light. A huge open iron door leads into a large room to\n"+
"the north. A tunnel leads south and back to the entrance.\n";

items = ({
  "ceiling",
  "The ceiling seems to be very smooth with only slight scratches\n"+
  "on its surface",
  "floor",
  "The floor is smooth but has very deep gouges on it",
  "walls",
  "The rock walls surrounding you seem very smooth and probably\n"+
  "worked by professional hands. There are many glowing symbols\n"+
  "on its surface",
  "symbols",
  "Ancient symbols that hold a great power. If only you could\n"+
  "somehow translate it",
  "door",
  "A large iron door that is most likely dwarven in craftsmanship",
});

dest_dir = ({
  "/players/maledicta/cont/dragon/rooms/cave6.c","north",
  "/players/maledicta/cont/dragon/rooms/cave3.c","south",
});

}

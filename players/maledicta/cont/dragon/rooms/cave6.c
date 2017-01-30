#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
#include "/players/maledicta/ansi.h"

object dragon;

reset(arg) {
if(!present("cont_dragon", this_object())){
dragon = clone_object("/players/maledicta/cont/dragon/mobs/bdragon3.c");
	move_object(dragon, this_object()); }
  if(arg) return;
set_light(1);

short_desc = ""+BOLD+"The "+HIB+"Dragons"+NORM+BOLD+" Cave"+NORM+"";
long_desc =
"  This chamber is the largest of all. It is decorated with many\n"+
"large banners and has a large painting on its ceiling. Several\n"+
"pillars lend support to the ceiling. An iron door leads south and\n"+
"back out to the subchamber. Here you also find even more symbols\n"+
"on the walls.\n";

items = ({
  "ceiling",
  "The ceiling seems to be very smooth with a large painting on its\n"+
  "surface",
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
  "painting",
  "A painting of a dwarven battle against evil",
  "banners",
  "The banners of many armies that no longer exist",
 
});

dest_dir = ({
  "/players/maledicta/cont/dragon/rooms/cave5.c","south",
});

}

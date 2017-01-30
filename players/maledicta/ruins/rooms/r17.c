#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(!present("archangel")){
  move_object(clone_object("/players/maledicta/ruins/mobs/iceangel2.c"), this_object()); }
  if(arg) return;
set_light(1);

short_desc = "The "+BOLD+""+BLK+"Ruins"+NORM+"";
long_desc =
"   Beyond the secret wall you find yourself in a skillfully crafted\n"+
"hallway.  This area seems completely untouched by the ravages that\n"+
"befell the outside structure.  A short hallway leads south to a well\n"+
"lit room\n";

items = ({
  "wall",
  "It has sealed itself shut, leaving no trace at all of its\n"+
  "existence, although you know at anytime you can leave",
  "hallway",
  "The hallway here has been spared the torment of the ruins, its\n"+
  "stone walls holding strong against the evil that pervades this\n"+
  "cursed place"
});

dest_dir = ({
  
  "/players/maledicta/ruins/rooms/r9.c","wall",
  "/players/maledicta/ruins/rooms/r18.c","south",
  
});

}

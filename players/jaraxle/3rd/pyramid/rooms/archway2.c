#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
  if(arg) return;
set_light(-1);

long_desc =
    ""+BLK+BOLD+"  The stone archway bends effortlessly to the west.\n"+
    "The shapes on the walls oddly change from squares\n"+
    "to circular blocks. An emblem has been chiseled into\n"+
    "the stone floor."+NORM+"\n"; 
items = ({
  "walls","Walls built with circular stones, set on top of each other",
  "blocks","Blocks made of hardened stone and clay",
  "emblem","A large emblem in the shape of a phoenix",
  "floor","Made of solid stone, there is an emblem chiseled into it",
  "archway","A curved overhang making a short walkway",
});

dest_dir = ({
  "/players/jaraxle/3rd/pyramid/rooms/archway.c","south",
  "/players/jaraxle/3rd/pyramid/rooms/archway3.c","west",
});

MOCO("/players/jaraxle/3rd/pyramid/mon/revenant.c"),TO);
}
short(){ return ""+BOLD+""+BLK+"Dark Pyramid"+NORM+""; }
realm() { return "NT"; }


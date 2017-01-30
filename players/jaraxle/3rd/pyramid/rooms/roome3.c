#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
  if(arg) return;
set_light(-1);

long_desc =
  ""+BLK+BOLD+"   A deep corner of the pyramid.  A gap between two columns to\n"+
  "the west lead into a small room.  To the south, a chest can be\n"+
  "seen in the middle of the hallway.  Broken patterns of spider\n"+
  "webs hang down the corner of the room."+NORM+"\n"; 
items = ({
  "pyramid","A large structure made from clay stone",
  "corner","A point in the pyramid where the east wall and north wall meet",
  "wall","You can look at the "+HIW+"east wall"+NORM+" or the "+HIW+"north wall"+NORM+"",
  "east wall","The east wall is gray in color, with hints of dark green",
  "north wall","The north wall looks old and cracked",
  "gap","A passageway to the west",
  "spider webs","Large creations of webs attached to the walls over the corner of the room",
  "webs","Large creations of webs attached to the walls over the corner of the room",
  "chest","A wooden chest in the hallway to the south",
  "columns","Thick columns of stacked clay cylindar blocks",
});

dest_dir = ({
  "/players/jaraxle/3rd/pyramid/rooms/roome2.c","south",
  "/players/jaraxle/3rd/pyramid/rooms/roomw2.c","southwest",
  "/players/jaraxle/3rd/pyramid/rooms/room3.c","west",
});

MOCO("/players/jaraxle/3rd/pyramid/mon/revenant.c"),TO);
MOCO("/players/jaraxle/3rd/pyramid/items/statue.c"),TO);
}
short(){ return ""+BOLD+""+BLK+"Dark Pyramid"+NORM+""; }
realm() { return "NT"; }


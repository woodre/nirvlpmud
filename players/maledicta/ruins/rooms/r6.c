#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "The "+BOLD+""+BLK+"Ruins"+NORM+"";
long_desc =
"   The floor in the hallway here is partially pooled over with dark\n"+
"stagnant water.  The walls and ceiling are crumbled and strewn about\n"+
"as if something powerful had demolished parts of it.  Deep scorch\n"+
"marks marr the stones of both. The hallway continues to the east and\n"+
"west. An archway with a charred door stands stands to the south.\n";

items = ({
  "stones",
  "Covered with deep scratch marks and huge burns, as if huge claws\n"+
  "a great heat had blasted and torn at them",	
  "floor",
  "You look closely and see that small streams of stagnant water\n"+
  "flow from a nearby wall and drip from the ceiling pooling it\n"+
  "over, otherwise you cannot tell much about it",
  "water",
  "It is covered with a thick sooty film and smells wretched",
  "walls",
  "The stones that used to make up the walls here are scratched and\n"+
  "mostly torn apart",
  "ceiling",
  "The ceiling here is partially demolished, as if something huge and\n"+
  "powerful had torn it apart",
  "marks",
  "The area here seems to be blasted with them. As if something very\n"+
  "hot and wickedly sharp had cut into the stones around you",
  "door",
  "It looks like it used to be very solid, possibly made of oak,\n"+
  "but now it lies broken and hanging freely from one hinge",
  "film",
  "A thick collection of burned wood fragments, and small specks\n"+
  "of stone",
  
});

dest_dir = ({
  "/players/maledicta/ruins/rooms/r3.c","west",
  "/players/maledicta/ruins/rooms/r8.c","east",
  "/players/maledicta/ruins/rooms/r7.c","south"
});

}

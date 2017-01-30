#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(!present("archangel")){
  move_object(clone_object("/players/maledicta/ruins/mobs/fireangel.c"), this_object()); }

  if(arg) return;
set_light(0);

short_desc = "The "+BOLD+""+BLK+"Ruins"+NORM+"";
long_desc =
"   The hallway here ends and T's leading to the north and south.  The\n"+
"walls and floor here are deeply scorched and blasted.  The ceiling is\n"+
"mostly intact with only a few cracks on its surface. The hallway also\n"+
"leads back to the west.\n";

items = ({
  "walls",
  "You're not sure what could have done such damage, but it is\n"+
  "extensive",
  "floor",
  "It is blackened and torn up in several places, the stones tossed about"+
  "the room haphazardly",
  "stones",
  "Torn from the floor, it seems from the looks of them that great claws"+
  "were used to tear them away",
  "ceiling",
  "It seems to be in good shape considering the condition of the rest of\n"+
  "of this place",
  "cracks",
  "Most likely formed from weathering and the heat that was in this place"
  
});

dest_dir = ({
  "/players/maledicta/ruins/rooms/r10.c","north",
  "/players/maledicta/ruins/rooms/r9.c","south",
  "/players/maledicta/ruins/rooms/r6.c","west",
});

}

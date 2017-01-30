/* the guardian can be found here, it is not aggro but will not allow further
   movements into the ruins. */
#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
	
 if(!present("guardian")){
 move_object(clone_object("/players/maledicta/ruins/mobs/guardian.c"), this_object());}		
  if(arg) return;
set_light(1);

short_desc = "The "+BOLD+""+BLK+"Ruins"+NORM+"";
long_desc =
"  This is the entryhall of the ruins.  Lying on the blackened floor\n"+
"are piles of stones and a rusted set of shackles. The roof here has\n"+
"collapsed, exposing the storm filled skies beyond. To the east the\n"+
"hallway continues leading into dark shadows.\n";

items = ({
  "shadows",
  "Deep and uninviting, you cannot penetrate the darkness that\n"+
  "fills the hallway",	
  "entryhall",
  "You search your surroundings, noticing the walls here are torn and\n"+
  "blasted as if some unnatural force had thrown its rage against it",
  "floor",
  "You look at the floor carefully and see that it has been torn up\n"+
  "by what looks like possible claw marks. It is also melted and burnt\n"+
  "in multiple places",
  "shackles",
  "An old set of shackles, they seem out of place even in this\n"+
  "mutilated environment",
  "roof",
  "You look carefully at the roof and see that it has been broken away,\n"+
  "exposing the hallway to the elements",
  "piles",
  "Made from the collapsed ceiling and torn walls and floor",
  "skies",
  "Dark and foreboding, they do not look pleasant",
  "stones",
  "Collected together into several large and small piles, they came from\n"+
  "the walls and ceiling"
});

dest_dir = ({
  "/players/maledicta/ruins/rooms/r1.c","out",
  "/players/maledicta/ruins/rooms/r3.c","east",
});

}

#include "/players/nikki/ansi.h"
#define TP this_player()
inherit "room/room";

reset(arg) {
   if(!arg) {
set_light(1);
short_desc = RED+"Castle Atrium"+NORM;
long_desc = RED+
 "   The noblemen and a few servants reside within this part of the castle.\n"+
 "The walls are dimly lit with torches that radiate light off of the brightly\n"+
 "embroidered tapestries hanging from the walls.  The smell of burning dried\n"+
 "seaweed from the fireplace is harsh in the air.  A large tapestry with the\n"+
 "symbol of the Pendragon hangs boldly above the fireplace.\n"+NORM;

items = ({
  "walls","The walls glisten with moisture from the dampness within the castle",
  "torches","The torches are made from thick driftwood soaked in oil",
  "tapestries","The tapestries dipict stories of battles from long ago",
  "fireplace","The enormous niche built within the thick castle walls is\n"+
              "blackened from the many fires burning within it's core",
  "tapestry","The magnificent Pendragon is proudfully embroidered with gold\n"+
             "is surrounded by the flag of Tintagel",
  "flag","The flag of Tintagel represents the unification of this\n"+
         "land and the great Goddess",
  "pendragon","The Pendragon is a symbol of the great power that Tintagel has\n"+
              "mastered from the knowledge of the Goddess and the dragon",
  
});

dest_dir = ( {
    "players/nikki/Tintagel/Rooms/square.c", "backward",
    
});
}}
init() {
  ::init();
    add_action("smell","smell");
}

smell(str) {
      if(!str) {
            write("What are you trying to smell?\n");
            return 1; }
   if(str == "air") {
	    write("The smell of sulphur is very offensive to your nostrils.\n");
	    return 1; }
	  else {
	    write("You smell the "+str+", but don't smell anything out of the ordinary.\n");
	    return 1; }  
}


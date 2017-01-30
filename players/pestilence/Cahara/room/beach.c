#include "/sys/lib.h"
#include "/players/pestilence/ansi.h"
#define TP this_player()
inherit "room/room";

reset(arg) {
  if(arg) return;


short_desc = ""+YEL+"Cahara Island Beach"+NORM+"";
long_desc =
  "    This is the beach on the Southern end of Cahara Island.  The beach\n"+
  "extends to the northeast and northwest.  The beach ends to the north, where\n"+
  "a well wooded forest begins.  The sea surrounds the area to the south, east,\n"+
  "and west.  Where the forest begins there is also a small path that begins aswell.\n";
set_light(1);

items = ({
"beach","A beach stretching to the northeast and northwest covered with sand",
"sea","A sea that you could possibly swim out of",
"forest","A forest full of trees to the north",
"trees","Large trees full with leaves extending high into the sky",
"path","A small worn dirt path leading to the north",
"dirt","It's brown dirt in the pathway",
});

dest_dir = ({
"/players/pestilence/Cahara/room/path.c","north",
});

}
init() {
  ::init();
     add_action ("swim_out","swim");
     }

swim_out(str) {
if(!str) { write("Swim where?\n");   return 1; }

     TP->move_player("swim#/players/pestilence/hall.c");
     write("You swim back to the "+HIR+"Hall of Images"+NORM+".\n");
     return 1;}

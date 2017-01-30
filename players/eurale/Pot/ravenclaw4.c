#include "DEF.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIY+"Ravenclaw Dormitory"+NORM;
long_desc =
  "  A long, retangular window fills most of the northern wall.  Rickety beds\n"+
  "with large trunks at their heads line the rest of the walls.  On the southern\n"+
  "wall is a large, open fireplace.  In the center of the room is a small, oval\n"+
  "table.\n";

items = ({
  "window","A large window with a metal handle that opens to let in fresh air\n"+
           "or any of the Ravenclaw owls",
  "poster beds","Old beds sitting on wooden legs that allow the owner to close off\n"+
         "his or her bed to the rest of the room when they want privacy",
  "trunks","Large trunks with leather handles for storing personal items",
  "fireplace","Dark from many fires, this stone fireplace provides warmth to the\n"+
              "room on chilly days",
  "table","A small wooden table for studying or playing wizard chess",
});

dest_dir = ({
  "players/eurale/Pot/ravenclaw2.c","west",
});

}

realm() { return "NT"; }

init() {
  ::init();
  add_action("Search","search");
}

Search(str) {
if(!str) { write("You search aimlessly but to no avail.\n"); return 1; }
write("You search the "+str+" but find nothing special.\n");
say(capitalize(TPRN)+" searches the "+str+" but finds nothing.\n");
return 1;
}

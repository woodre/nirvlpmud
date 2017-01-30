#include "DEF.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIB+"Hufflepuff Commons"+NORM;
long_desc =
  "  Six round tables with comforable, straight-backed chairs decorate this room.\n"+
  "Doorways to the sleeping quarters lead off to the right and left of the entry-\n"+
  "way.  A small, cozy fireplace adorns the outside wall and is flanked on either\n"+
  "side by a thin, tall window which provides light to the room.\n";

items = ({
  "tables","Round and approximately 6 feet in diameter, these scarred wooden\n"+
           "tables provide a place for the Hufflepuff housemates to study or\n"+
           "play games",
  "chairs","Nicely padded wooden-backed chairs",
  "doorways","Domed openings leading off into the male and female sleeping "+
             "quarters",
  "fireplace","A small, square opening with a stone hearth to catch any sparks\n"+
              "from the brilliant "+HIB+"blue fire"+NORM+" that burns",
  "window","Narrow, solid glass windows only there to provide light",
});

dest_dir = ({
  "players/eurale/Pot/hufflepuff.c","out",
  "players/eurale/Pot/hufflepuff3.c","left",
  "players/eurale/Pot/hufflepuff4.c","right",
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

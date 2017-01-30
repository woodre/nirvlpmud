#include "DEF.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIR+"Gryffindor Dormitory"+NORM;
long_desc =
  "  Four-poster beds adorn this living space where the members of Gryffindor lay\n"+
  "their weary heads to sleep after a long day of studying.  The smooth stone\n"+
  "floor has small rugs beside some of the beds, put there by the students.  A\n"+
  "large, multi-paned window looks out across the landscape and provides access to\n"+
  "any owls who might want to deliver something to the residents.\n";

items = ({
  "beds","Neatly made beds with trunks under some, no doubt storing valuable\n"+
         "school supplies and personal items",
  "trunks","Steamer type trunks of various colors",
  "floor","Dark stone worn smooth by many feet over hundreds of years",
  "rugs","Some bright, others with stiched scenes of Quiddich games",
  "window","A large, domed top window that can be opened for air or to let a\n"+
           "delivery owl in",
});

dest_dir = ({
  "players/eurale/Pot/gryffindor2.c","east",
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

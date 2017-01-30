#include "DEF.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIR+"Gryffindor Dormitory"+NORM;
long_desc =
  "  Situated about the room are four large beds.  The floor is covered with a\n"+
  "large, scarlet rug.  A large window looks out upon the Hogwarts yard and\n"+
  "provides light for the room.  The door to the west leads back into the Commons\n"+
  "of Gryffindor.\n";

items = ({
  "beds","Four poster beds with colorful curtains to provide the owner with privacy\n"+
         "to sleep or study.  Under most of the beds are large trunks used to transport\n"+
         "clothes and school items",
  "door","This door leads back into Gryffindor Commons where the house members meet to\n"+
         "study or talk about the day's events",
  "trunks","Large steamer trunks of various colors",
  "rug","A scarlet rug with the crest of Gryffindor on it",
  "window","A large, domed top window that can be opened for air or to let a\n"+
           "delivery owl in",
});

dest_dir = ({
  "players/eurale/Pot/gryffindor2.c","west",
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

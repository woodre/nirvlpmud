#include "DEF.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Hogwarts";
long_desc =
  "Long description.\n";

items = ({
  "item","Item description",
});

dest_dir = ({
  "players/eurale/Pot/hw0.c","north",
  "players/eurale/Pot/hw0.c","south",
  "players/eurale/Pot/hw0.c","east",
  "players/eurale/Pot/hw0.c","west",
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

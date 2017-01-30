inherit "/players/jareel/room";
#include "/players/jareel/define.h"

reset(arg) {
  if(!present("kassea"))  {
    MOCO("/players/jareel/monsters/town/kassea.c"),this_object());
}
  if(arg) return;
    set_light(1);

short_desc=(BLU+"Orlanth "+NORM+"Temple");

long_desc=

"   A very humbly decorated room in the Orlanthi Temple.  A simple\n"+
"cot and table rest within the room.  The person who resides here\n"+
"keeps the room incredibly neat.  A tapestry hangs on the northern\n"+
"wall with the runes of air and motion embroidered.  A door sits on\n"+
"the western wall.\n";


items = ({
  "tapestry","the tapestry covers the northern wall", 
  "door","The door is made of a hard wood",
  "doors","Doors sit on opposite ends of the room",
  "cot","The cot looks very uncomfortable to sleep on",
  "wall","The wall is engraved with the runes of Air and Motion",
  "walls","The walls is engraved with the runes of Air and Motion",
  "table","The wooden table seems to have a few runes carved into it",
  "runes on table","Runes of air and motion are etched into the table top",
  "runes","The runes of the Air and Motion decorate the walls",
  "flagstone","Large flat gray stones line the floor",
  "floor","Large gray flat stones line the floor.",
  "air","The air rune is a swirling circle encompassing itself",
  "motion","The motion rune has three arms curved out from a connecting point",
});

dest_dir = ({
"/players/jareel/areas/orlanthi_temple/rune_lord_quarters","west",
});
}
init() {
  ::init();
  add_action("Search","search");
}

Search(str) {
if(!str) { write("Search what?\n"); return 1; }
  write("You search the "+str+" but find nothing special.\n");
  say(this_player()->query_name()+" searches around for something.\n");
  return 1;
}

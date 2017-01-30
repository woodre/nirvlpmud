inherit "/players/jareel/room";
#include "/players/jareel/define.h"

reset(arg) {
  if(!present("henrik"))  {
    MOCO("/players/jareel/monsters/town/hendrik.c"),this_object());
}
  if(arg) return;
    set_light(1);

short_desc=(BLU+"Orlanth "+NORM+"Temple");

long_desc=
"     A very small sparsely decorated room in the back of the Orlanthi\n"+
"Temple.  A simple cot rests on the far wall.  The person who resides\n"+
"here does not dwell on material belongings.  The rune of Air and the\n"+
"rune of Motion are carved on the wall. Doors rest on the eastern and\n"+
"on the western walls.\n";


items = ({
 
  "door","The door is made of a hard wood",
  "doors","Doors sit on opposite ends of the room",
  "cot","The cot looks very uncomfortable to sleep on",
  "wall","The wall is engraved with the runes of Air and Motion",
  "walls","The walls is engraved with the runes of Air and Motion",
  "table","The wooden table seems to have a few runes carved into it",
  "runes","The runes of the Air and Motion decorate the walls",
  "flagstone","Large flat gray stones line the floor",
  "floor","Large gray flat stones line the floor.",
  "air","The air rune is a swirling circle encompassing itself",
  "motion","The motion rune has three arms curved out from a connecting point",
});

dest_dir = ({
"/players/jareel/areas/orlanthi_temple/shrine","west",
"/players/jareel/areas/orlanthi_temple/rune_priest_quarters","east",
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

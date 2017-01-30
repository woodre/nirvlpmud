inherit "/players/jareel/room";
#include "/players/jareel/define.h"

reset(arg) {
if(!present("guard")) {
MOCO("/players/jareel/monsters/town/orlanthi_infantry.c"),this_object());
MOCO("/players/jareel/monsters/town/orlanthi_infantry.c"),this_object());
MOCO("/players/jareel/monsters/town/orlanthi_infantry.c"),this_object());
MOCO("/players/jareel/monsters/town/orlanthi_infantry.c"),this_object());
}

if(!present("guard 4") && !present("guard 3") && !present("guard 2") && present("guard"))  {
MOCO("/players/jareel/monsters/town/orlanthi_infantry"),this_object());
MOCO("/players/jareel/monsters/town/orlanthi_infantry"),this_object());
MOCO("/players/jareel/monsters/town/orlanthi_infantry"),this_object());
}

if(!present("guard 3") && !present("guard 2") && present("guard"))  {
MOCO("/players/jareel/monsters/town/orlanthi_infantry"),this_object());
MOCO("/players/jareel/monsters/town/orlanthi_infantry"),this_object());
}

if(!present("guard 2") && present("guard"))  {
MOCO("/players/jareel/monsters/orlanthi_infantry.c"),this_object()); 
}
    if(arg) return;
    set_light(1);

short_desc=(BLU+"Orlanth "+NORM+"Temple");

long_desc=
"    The people who reside in the room have Spartan accommodations.\n"+
"Several cots rests along the walls.  The people who reside here keep \n"+
"the room militantly tidy.  A small wooden table rests in the center\n"+ 
"of the room.  The only exit seems to be a door to the north.\n";


items = ({
  
  "accommodations","The room has the barest of essentials in it",
  "cots","The cot looks very uncomfortable to sleep on",
  "cot","The cot looks very uncomfortable to sleep on",
  "wall","The walls are very undecorated",
  "walls","The walls are very undecorated",
  "table","The wooden table seems to have a few runes carved into it",
  "runes","The runes of the Air and Motion decorate the flat table",
  "flagstone","Large flat gray stones line the floor",
  "floor","Large gray flat stones line the floor.",
  "room","The room seems to be a military barracks",
  "stone","The floor is made of a gray rocks",
  "door","The door to the north leads out to the main temple",

});

dest_dir = ({
  "/players/jareel/areas/orlanthi_temple/shrine","north",
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

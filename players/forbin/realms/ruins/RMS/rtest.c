#include "/players/forbin/realms/ruins/ruinsdefine.h"
#include "/players/forbin/realms/ruins/ruinsshort.h"
inherit "/players/forbin/closed/std/room.c";


reset(arg) {
  if(arg) return;
set_light(-1);

short_desc = RUINS;
long_desc =
" You have entered an old armory. Racks of rusted weapons line the\n"+
"black scorched walls.  The stone floor here is covered with small\n"+
"piles of rocks and deep scorch marks.  To the north is the main\n"+
"hallway and to the east is an archway leading to another room.\n";
  

items = ({
  "piles",
  "Small scatterings of rocks and pebbles that have been torn away\n"+
  "from the floor, walls, and ceiling", 
  "floor",
  "The floor here is partially torn up, its stone surface marked\n"+
  "deeply by fiery burns. Small piles of rocks are scattered\n"+
  "across it",  
  "racks",
  "Charred and blackened themselves, they used to carry beautiful\n"+
  "weapons and shields",
  "weapons",
  "Damaged beyond use, it is hard to believe how many used to be\n"+
  "located here. Even for an armory, this was well stocked",
  "rocks",
  "Most likely broken from the walls and ceiling, they are small\n"+
  "and blackened",
  "marks",
  "You inspect the scorch marks carefully and to your surprise it\n"+
  "seems that several of them are in the shape of human bodies, as\n"+
  "if the victims here had been charred to ashes where they lie",
  "walls",
  "Something with great power has blasted the walls here"
  
  
});

dest_dir = ({
  RMS+"r03.c","north",
  RMS+"r07.c","east"
});

}

RSFUNC;

query_ruinsroom() { return 1; }
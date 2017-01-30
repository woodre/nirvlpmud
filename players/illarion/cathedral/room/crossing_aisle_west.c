#include "../def.h"

inherit "/players/illarion/room";

void reset(status arg) {
  if(arg) return;
  
  set_short("The Cathedral's Western Aisle");
  set_long("\
The aisles are the lower-ceilinged areas along the cathedral's east and west walls.  \
This section of the western aisle borders on the sanctuary.  It continues to the \
south and the north.  Little light reaches this part of the aisle, and the only remarkable \
feature is the doorway to the west, which leards to some sort of chapel.\
");

  set_light(1);

  add_exit("north",ROOM+"choir_aisle_west");
  add_exit("east",ROOM+"crossing");
  add_exit("south",ROOM+"nave_aisle_west");
  add_exit("west",ROOM+"west_chapel");
  
    
}

void init() {
  ::init();
}
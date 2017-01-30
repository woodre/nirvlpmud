#include "/obj/ansi.h"
inherit "players/earwax/housing/land.c";
inherit "room/room";
reset(arg) {
  if(arg) return;

short_desc = BLU + "Namekian Suburbs" + NORM;
long_desc = 
"A flat area of land extending east and west Mountains can\n"+
"be seen to the north, east, and south. To the west appears\n"+
"to be an open area.\n";
items = ({
"mountains","Mountain chain surrounding the suburbs",
});
set_light(1);
dest_dir = ({
"players/mosobp/areas/HOUSING/rooms/h10.c","west",
"players/mosobp/areas/HOUSING/rooms/h12.c","east",
});
set_realm_name("Namekian Suburbs");
set_lot_size(3);
set_cost(30500);
setup_land();
}

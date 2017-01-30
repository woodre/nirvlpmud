#include "/obj/ansi.h"
inherit "/players/earwax/housing/land.c";
inherit "room/room";
reset(arg) {
  if(arg) return;

short_desc = BLU + "Namekian Suburbs" + NORM;
long_desc = 
"Mountains a little to the north and making a barrier to the east.\n"+
"Make this area seem to be tiny. In the distance to the west, there is an\n"+
"outline of a building.\n";
items = ({
"mountains","There are mountains to the north and to the east",
"building","The building is hard to make out this far away",
});
set_light(1);
dest_dir = ({
"players/mosobp/areas/HOUSING/rooms/h7.c","west",
"players/mosobp/areas/HOUSING/rooms/h4.c","north",
"players/mosobp/areas/HOUSING/rooms/h12.c","south",
});
set_realm_name("Namekian Suburbs");
set_lot_size(2);
set_cost(20000);
setup_land();
}

#include "/obj/ansi.h"
inherit "/players/earwax/housing/land.c";
inherit "room/room";
reset(arg) {
  if(arg) return;

short_desc = BLU + "Namekian Suburbs" + NORM;
long_desc = 
"Mountains to the north and east make this area seem more protected.\n"+
"off to the south are more mountains, and way off in the west is the\n"+
"outline of a building.\n";
items = ({
"building","The building is hard to make out this far away",
"mountains","There are mountains to the north,east, and far to the south",
});
set_light(1);
dest_dir = ({
"players/mosobp/areas/HOUSING/rooms/h3.c","west",
"players/mosobp/areas/HOUSING/rooms/h8.c","south",
});
set_realm_name("Namekian Suburbs");
set_lot_size(8);
set_cost(400000);
setup_land();
}

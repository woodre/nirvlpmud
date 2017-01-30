#include "/obj/ansi.h"
inherit "/players/earwax/housing/land.c";
inherit "room/room";
reset(arg) {
  if(arg) return;

short_desc = BLU + "Namekian Suburbs" + NORM;
long_desc = 
"A flat area of land extending to the east and west, Mountains to \n"+
"the north and far to the south. A temple is off to the west, and\n"+
"more flat land to the south.\n";
items = ({
"mountains","A mountain range covers your view to the north",
"temple","A temple is barely visible to the west",
});
set_light(1);
dest_dir = ({
"players/mosobp/areas/HOUSING/rooms/h5.c","west",
"players/mosobp/areas/HOUSING/rooms/h7.c","east",
});
set_realm_name("Namekian Suburbs");
set_lot_size(4);
set_cost(100000);
setup_land();
}

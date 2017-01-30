#include "/obj/ansi.h"
inherit "players/earwax/housing/land.c";
inherit "room/room";
reset(arg) {
  if(arg) return;
 
short_desc = BLU + "Namekian Suburbs" + NORM;
long_desc = 
"This area of land appears to be very large. The only\n"+
"thing in sight is the mountains to the east, and a \n"+
"little ways to the south.\n";
items = ({
"mountains","There are mountains making a wall to the east and a little ways off to the south",
});
set_light(1);
dest_dir = ({
"players/mosobp/areas/HOUSING/rooms/h8.c","north",
"players/mosobp/areas/HOUSING/rooms/h16.c","south",
"players/mosobp/areas/HOUSING/rooms/h11.c","west",
});
set_realm_name("Namekian Suburbs");
set_lot_size(9);
set_cost(500000);
setup_land();
}

#include "/obj/ansi.h"
inherit "players/earwax/housing/land.c";
inherit "room/room";
reset (arg) {
 if(arg) return;

short_desc = BLU + "namekian Suburbs" + NORM;
long_desc = 
"Mountains make a wall to the south, and can be seen\n"+
"a little ways to the east. This area feels rather small.\n";
items = ({
"mountains","Mountains are to the south and to the east",
});
set_light (1);
dest_dir = ({
"players/mosobp/areas/HOUSING/rooms/h15.c","east",
"players/mosobp/areas/HOUSING/rooms/h13.c","west",
});
set_realm_name("Namekian Suburbs");
set_lot_size(2);
set_cost(15000);
setup_land();
}

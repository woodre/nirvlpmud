#include "/obj/ansi.h"
inherit "players/earwax/housing/land.c";
inherit "room/room";
reset (arg) {
  if(arg) return;

short_desc = BLU + "Namekian Suburbs" + NORM;
long_desc = 
"Rolling hills to the west and mountains to the south make this\n"+
"areas appear feel small.  Mountains can also barely be \n"+
"made out to the west.\n";
items = ({
"hills","Rolling hills to the west appear to go on forever",
"mountains","There are mountains to the south and far off in the east",
});
set_light(1);
dest_dir = ({
"players/mosobp/areas/HOUSING/rooms/h9.c","north",
"players/mosobp/areas/HOUSING/rooms/h14.c","east",
});
set_realm_name("Namekian Suburbs");
set_lot_size(1);
set_cost(10000);
setup_land();
}

#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
#include "/players/maledicta/ansi.h"


reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "The Caves of the "+HIR+"Red "+NORM+RED+"Dragon Clan"+NORM;
long_desc =
"  This tunnel is slightly more narrow than the others\n"+
"before it. The walls here are rougher and small piles\n"+
"of rocks litter the area from where they fell from them.\n"+
"The tunnel continues to the west, or to the south and\n"+
"into the main chamber.\n";
items = ({
"walls",
"The walls here are made from the same black rock, but are\n"+
"much more rough and cracked",
"piles",
"Small piles of black rock that have fallen from the walls",
});

dest_dir = ({
  "/players/maledicta/cont/rdragon/rooms/r2.c","south",
  "/players/maledicta/cont/rdragon/rooms/r4.c","west",
});
}

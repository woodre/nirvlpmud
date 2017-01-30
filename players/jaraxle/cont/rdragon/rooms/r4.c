#define tp this_player()

#define tpn this_player()->query_name()

#define tpp this_player()->query_possessive()

inherit "room/room";

#include "/players/jaraxle/ansi.h"





reset(arg) {



if(!present("elven prisoner", this_object())){

move_object(clone_object("/players/jaraxle/cont/mobs/prisoner"), this_object());

}

if(!present("undead dragon", this_object())){

move_object(clone_object("/players/jaraxle/cont/mobs/undead_dragon"), this_object());

}

  if(arg) return;

set_light(1);



short_desc = "The Caves of the "+HIR+"Red"+NORM+RED+"Dragon Clan"+NORM;

long_desc =

"You have come to a small cul-de-sac. Along the walls are\n"+

"numerous sets of rusted chains and torture devices. The\n"+

"floor here is caked with dried blood, the stench carrying\n"+

"through to your nostrils. To the east the tunnel leads\n"+

"back to the main chamber.\n";

items = ({

"walls",

"The walls here are rough and have numerous chains mounted\n"+

"to them",

"devices",

"Several devices used to inflict pain, or extract information",

"floor",

"A rough uneven floor with numerous deep gouges and large\n"+

"amounts of dried blood spread about",

"blood",

"A dark crusted goo that has collected along the floor",

});



dest_dir = ({

  "/players/jaraxle/cont/rdragon/rooms/r3.c","east",

});

}


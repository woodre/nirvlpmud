#define tp this_player()

#define tpn this_player()->query_name()

#define tpp this_player()->query_possessive()

inherit "room/room";

#include "/players/jaraxle/ansi.h"

object civ;

object civ2;

object child;

reset(arg) {

if(!present("cont_lizardman", this_object())){

        civ = clone_object("/players/jaraxle/cont/ltown/mobs/lcivilian.c");

	move_object(civ, this_object());

	civ2 = clone_object("/players/jaraxle/cont/ltown/mobs/lcivilian.c");

	move_object(civ, this_object());

	}

if(!present("cont_lizardchild", this_object())){

	child = clone_object("/players/jaraxle/cont/ltown/mobs/lchild.c");

	move_object(child, this_object());

	}	

  if(arg) return;

set_light(1);



short_desc = "Third Earth ["+HIG+"Terk'ula"+NORM+"]";

long_desc =

"   You are on the main road of Terk'ula. To the west\n"+

"is a small shop that sells equipment, and to the east\n"+

"is a small hut. The road continues to the north and\n"+

"south. All around you can see the large wooden fence\n"+

"that surrounds this village.\n";



items = ({

  "street",

  "A dirt road that leads through the center of town",

  "shop",

  "A small building made of rock and sealed with mud",

  "hut",

  "A small mud and wood hut that is probably a private residence.\n"+

  "It has a large pool of water that extends out of the backside",

  "road",

  "A dirt road that leads through the center of town",

  "fence",

  "A tall wooden wall that defends the village from attacks",

});



dest_dir = ({

  "/players/jaraxle/cont/ltown/rooms/l3.c","north",

  "/players/jaraxle/cont/ltown/rooms/hut1.c", "east",

  "/players/jaraxle/cont/ltown/rooms/lshop.c", "west",

  "/players/jaraxle/cont/ltown/rooms/l1.c", "south",

});



}




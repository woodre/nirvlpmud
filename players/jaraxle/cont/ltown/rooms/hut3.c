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

	move_object(civ2, this_object());

	}	

if(!present("cont_lizardchild", this_object())){

child = clone_object("/players/jaraxle/cont/ltown/mobs/lchild.c");

	move_object(child, this_object());	

}

  if(arg) return;

set_light(1);



short_desc = "Third Earth ["+HIG+"Terk'ula"+NORM+"]";

long_desc =

"  You stand inside a hut made from wood and mud. The walls are\n"+

"very smooth and the floor is slightly muddy. A large pool of\n"+

"water can be found at the rear of the hut. Its waters seem very\n"+

"clear. A small wooden door leads out.\n";



items = ({

  "pool",

  "A large pool of water that sparkles in the available light",

  "water",

  "The water here is clear",

  "door", 

  "A small wooden door",

});



dest_dir = ({

  "/players/jaraxle/cont/ltown/rooms/l3.c", "out",

});



}


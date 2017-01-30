#define tp this_player()

#define tpn this_player()->query_name()

#define tpp this_player()->query_possessive()

inherit "room/room";

#include "/players/jaraxle/ansi.h"

int searched;

object owner;

object child;



reset(arg) {

if(!present("cont_lizardguard")){

	owner = clone_object("/players/jaraxle/cont/ltown/mobs/lguard.c");

	move_object(owner, this_object());

	}

if(!present("cont_lizardchild")){

	child = clone_object("/players/jaraxle/cont/ltown/mobs/lchild.c");

	move_object(child, this_object());

	}	

  if(arg) return;

set_light(1);

searched = 0;

short_desc = "Third Earth ["+HIG+"Terk'ula"+NORM+"]";

long_desc =

"  You stand inside a hut made from wood and mud. The walls are\n"+

"very smooth and the floor is slightly muddy. A large pool of\n"+

"water can be found at the rear of the hut. Its waters seem very\n"+

"clear. A medium sized table stands in the center of the room with\n"+

"three chairs around it. A small wooden door leads out.\n";



items = ({

  "table",

  "A nice table that looks to have dinner set on it. You can\n"+

  "search the table to see if there is anything of use",

  "chairs",

  "Decent chairs that surround the table",

  "pool",

  "A large pool of water that sparkles in the available light",

  "water",

  "A large pool of water that sparkles in the available light",

  "door", 

  "A small wooden door",

  "floor",

  "The floor is made of a hard dirt and mud",

});



dest_dir = ({

  "/players/jaraxle/cont/ltown/rooms/l3.c", "out",

});



}



init(){

::init();

add_action("search_it", "search");

}



search_it(str){

if(!str){

write("search what?\n");

return 1;

}

if(str != "table"){

write("search what?\n");

return 1;

}



if(present("cont_lizardguard", this_object())){

write("The lizardman hisses, 'Thats Mine! Stay away!'\n");

return 1;

}



if(!searched){

move_object(clone_object("/players/jaraxle/cont/ltown/objects/meat.c"), this_object());

command("look", this_player());

write("You search the table for useful items and find something!\n");

searched = 1;

return 1;

}



write("You find nothing of interest.\n");

return 1;

}


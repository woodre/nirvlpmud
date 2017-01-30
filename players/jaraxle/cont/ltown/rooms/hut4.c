#define tp this_player()

#define tpn this_player()->query_name()

#define tpp this_player()->query_possessive()

inherit "room/room";

#include "/players/jaraxle/ansi.h"

int searched;

object guard1;



reset(arg) {
/*
  if(!present("symbiote", this_object())){
move_object(clone_object("/players/jaraxle/cont/ltown/mobs/lc.c"),this_object());
}
*/

	if(arg) return;

set_light(1);

searched = 0;

short_desc = "Third Earth ["+HIG+"Terk'ula"+NORM+"]";

long_desc =

"  This is a very old and broken down hut. In the center of\n"+

"the room is a small table with two chairs. At the back of\n"+

"the hut is a large pool of water which seems stagnant and\n"+

"smells of rot and disease. A curtain leads out into the\n"+

"street.\n";



items = ({

  "street",

  "A dirt road that leads through the center of town",

  "table",

  "A very old and not well put together table",

  "chairs",

  "A couple of chairs that don't seem very sturdy",

  "pool",

  "A large pool of water with a dense film of goo covering it. If you\n"+

  "dare you could 'search' it",

  "water",

  "A large pool of water with a dense film of goo covering it. If you\n"+

  "dare you could 'search' it",

  "curtain", 

  "A rotting curtain that does nothing to keep the wind out",

});



dest_dir = ({

  "/players/jaraxle/cont/ltown/rooms/l5.c", "out",

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

if(str == "pool" || str == "water"){

if(random(100) < 30){

write("Something bites your hand!\n");

this_player()->hit_player(random(20) + 10);

say(this_player()->query_name()+" pulls back in pain!\n");

return 1;

}

write("You reach your hand into the filthy water and feel around...\n");

if(searched){

write("You find nothing.\n");

return 1;

}

if(!searched){

write("You feel around and find something solid!\n"+

      "You drag it up into the room.\n");

move_object(clone_object("/players/jaraxle/cont/ltown/objects/chest.c"), this_object());

searched = 1;

return 1;

}

}

write("Search what?\n");

return 1;

}

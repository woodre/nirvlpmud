#define tp this_player()

#define tpn this_player()->query_name()

#define tpp this_player()->query_possessive()

inherit "/players/jaraxle/room.c";

#include "/players/jaraxle/ansi.h"





reset(arg) {
if(!present("cont_dragon", this_object())){

move_object(clone_object("/players/jaraxle/cont/mobs/bdragon4"),
this_object());
move_object(clone_object("/players/jaraxle/cont/mobs/bdragon4"),
this_object());

}

  if(arg) return;

set_light(1);



short_desc = "The Caves of the "+HIB+"Blue "+NORM+BLU+"Dragon Clan"+NORM;

long_desc =

" This is a large open cavern.  A huge hole spans most of the\n"+

"distance across the room leading down into an even larger\n"+

"chamber. A small stream of lava flows down the wall to your\n"+

"right. A tunnel leads further into the volcano to the west.\n";



items = ({

"hole",

"A huge hole that spans most of the chamber and leads down into\n"+

"a larger room",

"stream",

"A small stream of molten rock that flows from the wall to a\n"+

"crack in the floor",

"crack",

"A large crack with lava flowing into it",

"lava",

"Molten hot rock",

"wall",

"A wall of black volcanic stone. It is smooth",

});



dest_dir = ({

  "/players/jaraxle/cont/bdragon/rooms/r11.c","west",

  "/players/jaraxle/cont/bdragon/rooms/r9.c","down"

});



}


void init() {

  ::init();


 add_action("no_ns", "down");

  add_action("no_ns", "south");

  if(find_call_out("flames") == -1)

   call_out("flames", random(10) + 3);

  }

no_ns(){

if(present("cont_dragon", this_object())){

write("The Elite Guard Dragon blocks your way around the core.\n");

return 1;

}

return;

}

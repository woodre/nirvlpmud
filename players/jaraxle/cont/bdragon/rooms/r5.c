#define tp this_player()

#define tpn this_player()->query_name()

#define tpp this_player()->query_possessive()

inherit "/players/jaraxle/room.c";

#include "/players/jaraxle/ansi.h"





reset(arg) {

if(!present("cont_dragon", this_object())){

move_object(clone_object("/players/jaraxle/cont/mobs/bdragon1"), this_object());

}

  if(arg) return;

set_light(1);



short_desc = "The Caves of the "+HIB+"Blue "+NORM+BLU+"Dragon Clan"+NORM;

long_desc =

"  The tunnel here spreads outward into a vast area. The walls\n"+

"are smooth and warm to the touch, small amounts of steam rising\n"+

"out from cracks in them.  A large hole stands in the center of\n"+

"the room, a gush of hot air flowing from it. To the west is a\n"+

"long tunnel with a deep glow coming from it. To the south is\n"+

"a side chamber filled with darkness.\n";



items = ({

"walls",

"Smooth black walls that have a warmth flowing from it. Small\n"+

"cracks have formed along them with steam rising from each",

"steam",

"A small mist of hot steam",

"cracks",

"Deep cracks that have formed in the black stone walls",

"hole",

"A large hole that fills the center of the room. Steam rises\n"+

"from it in great gushes",

"air",

"A hot spray of air that fills the room",

"tunnel",

"A long glowing tunnel that leads deeper into the volcanic\n"+

"mountain",

});



dest_dir = ({

  "/players/jaraxle/cont/bdragon/rooms/r7.c","south",

  "/players/jaraxle/cont/bdragon/rooms/r2.c","east",

  "/players/jaraxle/cont/bdragon/rooms/r6.c","west",

});



}



/* Thanks Feldegast for providing an easy template for messages */



int peeps;



void init() {

  ::init();

  peeps++;

  add_action("no_go", "west");

  if(find_call_out("flames") == -1)

   call_out("flames", random(10) + 3);

  }



no_go(){

  if(present("cont_dragon", this_object())){

   write("The dragon slides in front of you and blocks entrance!\n");

   return 1;

   }

  return;

  }





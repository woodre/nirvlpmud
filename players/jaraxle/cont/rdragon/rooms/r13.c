#define tp this_player()

#define tpn this_player()->query_name()

#define tpp this_player()->query_possessive()

inherit "room/room";

#include "/players/jaraxle/ansi.h"





reset(arg) {

if(!present("cont_dragon", this_object())){

move_object(clone_object("/players/jaraxle/cont/mobs/rdragon4.c"), this_object());

}

  if(arg) return;

set_light(1);



short_desc = "The Caves of the "+HIR+"Red"+NORM+RED+"Dragon Clan"+NORM;

long_desc =

"  Looking out, you find that you stand at the lip to the\n"+

"volcanoes core. Far below is a smoldering cauldron of\n"+

"molten rock, the heat traveling swiftly on strong currents\n"+

"of air up and out of the top far above. A small path leads\n"+

"north and south around the edge of the volcano, circling\n"+

"about and meeting an outcropping on the opposite side of\n"+

"the chamber. There is a tunnel leading back down and away\n"+

"from the core.\n";

 

items = ({

"core",

"The molten core of the center of the volcano. It is a huge\n"+

"bubbling mass of glowing red liquid",

"top",

"A rocky lip of the top of the volcano. It is high overhead",

"path",

"A narrow stone path that leads north and south around the\n"+

"volcanoes core",

"outcropping",

"A large stone outcropping that extends out and over the\n"+

"molten core of the volcano",

"molten rock",

"A bubbling mass of liquified stone",

"rock",

"A bubbling mass of liquified stone",

});



dest_dir = ({

  "/players/jaraxle/cont/rdragon/rooms/r14.c","north",

  "/players/jaraxle/cont/rdragon/rooms/r19.c","south",

  "/players/jaraxle/cont/rdragon/rooms/r12.c","east",



});



}



/* Thanks Feldegast for providing an easy template for messages */



int peeps;



void init() {

  ::init();

  peeps++;

  add_action("no_ns", "north", 1);

  add_action("no_ns", "south", 1);

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



void exit() {

  peeps--;

  if(peeps <= 0)

    while(remove_call_out("flames") != -1) ;

  }



void flames() {

  object ob,next;

  string msg;



  switch(random(4)) {

    case 0: msg= HIR+"Lava"+NORM+" burns brightly far below.\n"; break;

    case 1: msg= "The molten rock of the core flows about lazily.\n"; break;

    case 2: msg= "Red light, almost unbearable to see, reflects off of the walls.\n"; break;

    case 3: msg= "A heated gust of wind rises from the core and sweeps over you.\n"; break;

    }

  tell_room(this_object(),msg);

  call_out("flames", random(10) + 3); 

  }


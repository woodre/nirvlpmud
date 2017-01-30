#define tp this_player()

#define tpn this_player()->query_name()

#define tpp this_player()->query_possessive()

inherit "/players/jaraxle/room.c";

#include "/players/jaraxle/ansi.h"





reset(arg) {

  if(arg) return;

set_light(1);



short_desc = "The Caves of the "+HIB+"Blue "+NORM+BLU+"Dragon Clan"+NORM;

long_desc =

"  You stand on a narrow path leading around the core of the\n"+

"volcano. Looking over the edge you see a huge lava pool far\n"+

"below. The wall here is partially collapsed and steam escapes\n"+

"from a small gap in it. The path continues north to the out-\n"+

"cropping, or east back towards the entrance of the core.\n";



items = ({

"core",

"The molten core of the center of the volcano. It is a huge\n"+

"bubbling mass of glowing red liquid rock",

"path",

"A narrow stone path that leads south and east around the\n"+

"volcanoes core",

"outcropping",

"A large stone outcropping that extends out and over the\n"+

"molten core of the volcano",

"molten rock",

"A bubbling mass of liquified stone",

"pool",

"A large pool of lave far below",

"edge",

"A short rocky edge that overlooks the lava pool below",

"wall",

"The wall is made of a rough black stone with a large gap in it. Steam\n"+

"escapes from the gap in large gusts. If you are careful you might be\n"+

"able to squeeze into it. But it could be very dangerous"

});



dest_dir = ({

  "/players/jaraxle/cont/bdragon/rooms/r19.c","east",

  "/players/jaraxle/cont/bdragon/rooms/r16.c","north",

});



}



/* Thanks Feldegast for providing an easy template for messages */



int peeps;



void init() {

  ::init();

  peeps++;

  if(find_call_out("flames") == -1)

   call_out("flames", random(10) + 3);

  add_action("squeeze", "squeeze");

  }



squeeze(str){

 if(!str){ write("Squeeze into what?\n"); return 1; }

 if(str == "into gap" || str == "gap" || str == "wall" || str == "into wall"){

  tell_object(this_player(), "\nYou squeeze into the gap...\n\n");

  if(random(100) < 70){

    tell_object(this_player(), "A gust of steam rises from the gap and engulfs you! You fail.\n\n");

    this_player()->hit_player(random(40) + 1);

    return 1;

    }

  move_object(this_player(), "/players/jaraxle/cont/bdragon/rooms/r20.c");

  command("look", this_player());

  tell_room(environment(this_player()), this_player()->query_real_name()+" arrives.\n", ({ this_player() }));

  return 1;

  }

  write("squeeze into what?\n");

  return 1;

}



/*
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

*/

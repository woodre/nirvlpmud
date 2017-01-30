#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
/*
if(!present("portal")) {
move_object(clone_object("/players/daranath/qualtor/obj/portal2.c"),this_object());
}
*/
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(South Gate)");
    long_desc=
"               "+BOLD+"Shield Street"+NORM+" (north)\n"+
"The southern gateway leading into Qual'tor lies in ruins, having fallen to\n"+
"invaders during the massive fighting for control of the city. Large piles \n"+
"of stone rubble are all that is left, blocking travelers from entering or\n"+
"leaving through the gateway.\n";

    items=({
     "stone","The stone from the gateway has collapsed upon itself",
     "rubble","The rubble is from the fallen gatehouse",
     "gateway","The gate itself was a pair of towers flanking a drawbridge\n"+
               "at one time, much like the northgate does now",
     "ruins","The ruins of the gateway are all about you",
    });

    dest_dir=({
      "/players/daranath/qualtor/east_road5.c","north",
    });

    }
  }

    init(){
      ::init();
add_action("search","search");
add_action("climb_down","down");
    }

    search(){
write("Moving some of the rubble aside, you uncover a large hole that you can\n"+
     "climb <"+HIR+"down"+NORM+"> into.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

climb_down(){
write("The Dark Dungeon is currently under construction. Coming soon...\n"+
      "     -Dar\n");
return 1;
}

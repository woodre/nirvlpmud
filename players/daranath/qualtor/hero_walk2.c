#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(City Ward)");
    long_desc=
"               "+BOLD+"Heroes Walk"+NORM+" (east, west)\n"+
"City Ward's most beloved treasure has always been Heroes Walkway.\n"+
"So, when the city was rebuilt, this small walkway was the first thing\n"+
"on the list to repair. A small garden can be see just to the north\n"+
"of the walkway itself, adding to the tranquility here.\n";

    items=({
     "roadway","The roadway is made of stone and gravel",
    });

    dest_dir=({
      "/players/daranath/qualtor/hero_garden.c","north",
      "/players/daranath/qualtor/grif_flight1.c","east",
      "/players/daranath/qualtor/hero_walk1.c","west",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("A quick search of the area brings nothing of value.\n");
    say(tp +" searches the area.\n");
     return 1;
    }



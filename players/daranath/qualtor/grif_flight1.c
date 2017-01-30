#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(City Ward)");
    long_desc=
"               "+BOLD+"Griffin's Flight"+NORM+" (north, south)\n"+
"               "+BOLD+"Heroes Walk"+NORM+" (west)\n"+
     "Griffin's Flight is a small road within Qual'tor that circles around\n"+
     "the western edge of the market's ruins. The road itself crosses\n"+
     "with the eastern end of hero's walk and the east road continues\n"+
     "to the south.\n";

    items=({
     "road","East road is made of stone and gravel",
     "ruins","The arena's ruins are a blackened and burnt out shell",
    });

    dest_dir=({
      "/players/daranath/qualtor/grif_flight2.c","north",
      "/players/daranath/qualtor/east_road3.c","south",
      "/players/daranath/qualtor/hero_walk2.c","west",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("A quick search of the roadway brings nothing of value.\n");
    say(tp +" searches the area.\n");
     return 1;
    }



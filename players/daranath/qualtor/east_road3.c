#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(City Ward)");
    long_desc=
"               "+BOLD+"Griffin's Flight"+NORM+" (north)\n"+
"               "+BOLD+"East Road"+NORM+" (east, southwest)\n"+
     "The east road coils about the southern end of Qual'tor, heading\n"+
     "from the Central plaza and the Black Rose tavern to a another\n"+
     "bar called the Phoenix. A smaller road heads off to the\n"+
     "north from here.\n";

    items=({
     "road","East road is made of stone and gravel",
     "tavern","The Black Rose Tavern is a new building within Qual'tor's ruins,\n"+
              "standing on the site of another former inn. The black\n"+
              "rose gets its name from the dark, rose tinted wood used\n"+
              "during its construction",
     "phoenix","The Phoenix is a small bar known for its ruffians",
     "bar","The bar to the east is called the Phoenix",
    });

    dest_dir=({
      "/players/daranath/qualtor/grif_flight1.c","north",
/*
      "/players/daranath/qualtor/mansion/lot9.c","south",
*/
      "/players/daranath/qualtor/east_road4.c","east",
      "/players/daranath/qualtor/east_road2.c","southwest",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("A quick search of the crossroads brings nothing of value.\n");
    say(tp +" searches the area.\n");
     return 1;
    }



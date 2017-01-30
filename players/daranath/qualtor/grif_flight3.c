#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(City Ward)");
    long_desc=
"               "+BOLD+"Griffin's Flight"+NORM+" (north, south)\n"+
"               "+BOLD+"Dagger Alley"+NORM+" (east)\n"+
     "Griffin's Flight continues from here, just to the east of\n"+
     "Dagger Alley. The alley itself lies just to the south of the\n"+
     "former market within the city, a place where many foodstuffs\n"+
     "and various items were sold. Griffin's Flight runs north\n"+
     "and south from here.\n";

    items=({
     "alley","Dagger alley lies between a couple of burnt ruins",
     "road","East road is made of stone and gravel",
    });

    dest_dir=({
      "/players/daranath/qualtor/grif_flight4.c","north",
      "/players/daranath/qualtor/dag_alley.c","east",
      "/players/daranath/qualtor/grif_flight2.c","south",
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



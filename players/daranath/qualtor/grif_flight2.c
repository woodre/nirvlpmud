#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(City Ward)");
    long_desc=
"               "+BOLD+"Griffin's Flight"+NORM+" (north, south)\n"+
     "Griffin's Flight continues to wind around the former market. The\n"+
     "other side of the road has been completly destroyed during the\n"+
     "chaotic times. The roadway runs north and south from here.\n";

    items=({
     "road","East road is made of stone and gravel",
     "ruins","The arena's ruins are a blackened and burnt out shell",
    });

    dest_dir=({
      "/players/daranath/qualtor/grif_flight3.c","north",
      "/players/daranath/qualtor/grif_flight1.c","south",
/*
      "/players/daranath/qualtor/mansion/lot8.c","west",
*/
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



#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(Arena Ward)");
    long_desc=
"               "+BOLD+"Triumph Circle"+NORM+" (north)\n"+
"               "+BOLD+"Shield Street"+NORM+" (south)\n"+
"               "+BOLD+"Falcon Lane"+NORM+" (west)\n"+
     "North road ends here, travelling back to the west while Shield\n"+
     "street runs south into the city. The outer wall lies just east\n"+
     "in pieces, having been severly damaged during the tremendous\n"+
"fighting that brought the city to its downfall. A newly \n"+
"cleared roadway leads north, torwards the old Arena Ward.\n";

    items=({
     "wall","The outer wall lies in ruins",
     "walls","The outer walls lies in ruins",
     "road","North road is made of a dark grey gravel",
     "street","Shield street runs south from here, along the many personal villas\n"+
              "that once ran along both sides of the street",
    });

    dest_dir=({
      "/players/daranath/qualtor/newstuff/triumph1.c","north",
      "/players/daranath/qualtor/shield_st4.c","south",
      "/players/daranath/qualtor/nor_road4.c","west",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
add_action("dar_south","south");
    }

    search(){
    write("A quick search of the area reveals nothing.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

dar_south() {
write("You leave the utter chaos of the area you are in and enter\n\n"+
      "               "+HIW+"City Ward"+NORM+"\n\n"+
      "You feel a sense of relief as you begin to relax a bit.\n");
return 0;
}


#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
short_desc= (BOLD+BLK+"City of Qual'tor "+NORM+"(City Ward)");
    long_desc=
"               "+BOLD+"Shield Street"+NORM+" (north, south)\n"+
"               "+BOLD+"Coin Alley"+NORM+" (west)\n"+
"Shield street continues to the north and south from here, along\n"+
"the eastern side of Qual'tor. A large personal villa lines one\n"+
"side of the street, while Coin Alley opens up to the west.\n";

    items=({
     "wall","The outer wall lies in ruins",
     "walls","The outer wall lies in ruins",
"villa","A large personal villa is being built along the eastern\n"+
       "side of Shield street. Another good sign of Qual'tors rebirth",
     "villas","Most of the personal villas are empty and abandoned",
    });

    dest_dir=({
      "/players/daranath/qualtor/shield_st3.c","north",
      "/players/daranath/qualtor/shield_st1.c","south",
      "/players/daranath/qualtor/coin_alley.c","west",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("A quick search of Shield street reveals nothing.\n");
    say(tp +" searches the area.\n");
     return 1;
    }


#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/newstuff/"
inherit "room/room";

reset(int arg){
if(!present("kaya")) {
move_object(clone_object(ROOT+"mon/kaya.c"),this_object());
}
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(City Ward)");
    long_desc=
"               "+BOLD+"Shield Street"+NORM+" (north, south)\n"+
"               "+BOLD+"Market Pathway"+NORM+" (east)\n"+
"               "+BOLD+"East Road"+NORM+" (west)\n"+
"The eastern roads ends at a large open area, with several small\n"+
"shops being built nearby. The new Merchant's Square is going up,\n"+
"with exotic items from all over Nirvana to be sold to the east.\n"+
"A road leads north from the square, while the ruined southgate\n"+
"is just south from here.\n";

    items=({
     "bar","The Pheonix has long since burnt to the ground",
     "stone","The stone from the building is blackened from fire",
    });

    dest_dir=({
      "/players/daranath/qualtor/shield_st1.c","north",
      "/players/daranath/qualtor/south_gate.c","south",
      "/players/daranath/qualtor/newstuff/market_path1.c","east",
      "/players/daranath/qualtor/east_road4.c","west",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("You find nothing about the darkened shadows.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

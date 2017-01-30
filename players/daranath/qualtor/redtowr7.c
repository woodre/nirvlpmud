#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
short_desc= (BOLD+BLK+"City of Qual'tor "+NORM+"("+RED+"RedTower"+NORM+")");
    long_desc=
     "The tight spiral staircase climbs its way into the tower, making\n"+
     "its path up to the battlements above. A small archway in the \n"+
     "wall leads to a small reading chamber here, many of its\n"+
     "books dating back dozens of years.\n";

    items=({
     "books","You need to be in the chamber to look at the books",
     "chamber","A plush reading room sits within the archway",
     "archway","The archway enters into a small reading chamber",
     "book","You need to be in the chamber to look at a book",
     "stair","The stair leads up and down from here",
     "battlements","The battlements are on the roof",
    });

    dest_dir=({
      "/players/daranath/qualtor/redtowr8.c","up",
      "/players/daranath/qualtor/redtowr1.c","down",
      "/players/daranath/qualtor/redtowr_li.c","archway",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("You find nothing of interest within the stairwell.\n");
    say(tp +" searches the area.\n");
     return 1;
    }



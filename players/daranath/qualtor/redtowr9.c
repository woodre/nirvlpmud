#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
short_desc= (BOLD+BLK+"City of Qual'tor "+NORM+"("+RED+"RedTower"+NORM+")");
    long_desc=
     "The tight spiral staircase climbs its way into the tower, making\n"+
     "its path up to the battlements above. An ornate marble archway\n"+
     "leads to a plush chamber within, an overdone bedroom of sorts.\n"+
     "Just above your current position, the staircase empties out\n"+
     "onto the top of the Red Tower, allowing one to view the city\n"+
     "or at least whats left of it.\n";

    items=({
     "chamber","The chamber within is full of silks and satins",
     "bedroom","Just whose bedroom could this be",
     "marble","White marble makes up the archway, clashing with the\n"+
         "red stone of the tower",
     "stair","The stair leads up and down from here",
     "battlements","The battlements are on the roof",
    });

    dest_dir=({
      "/players/daranath/qualtor/redtowr_tp.c","up",
      "/players/daranath/qualtor/redtowr8.c","down",
      "/players/daranath/qualtor/redtowr_kp.c","archway",
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



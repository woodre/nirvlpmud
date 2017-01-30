#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
move_object(clone_object("/players/daranath/qualtor/mon/mourn_coil.c"),this_object());
  if(!arg){
    
    set_light(1);
short_desc= (BOLD+BLK+"City of Qual'tor "+NORM+"("+RED+"RedTower"+NORM+")");
    long_desc=
     "The tight spiral staircase climbs its way into the tower, making\n"+
     "its path up to the battlements above. A stone archway in the\n"+
     "wall leads to a large chamber that smells of sulpher and\n"+
     "brimstone, an ominous combination of smells for this city.\n";

    items=({
     "chamber","The large chamber looks to be an alchemy of some sort",
     "stair","The stair leads up and down from here",
     "battlements","The battlements are on the roof",
    });

    dest_dir=({
      "/players/daranath/qualtor/redtowr9.c","up",
      "/players/daranath/qualtor/redtowr7.c","down",
      "/players/daranath/qualtor/redtowr_al.c","archway",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    add_action("dar_up","up");
    }

    search(){
    write("You find nothing of interest within the stairwell.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

    dar_up() {
  if(present("coil")) {
  write("The Mourning Coil prevents you from ascending up into the tower.\n"+
        "It must be protecting something.\n");
  return 1; }
return 0; }

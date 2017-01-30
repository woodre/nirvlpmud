#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
move_object(clone_object("/players/daranath/qualtor/mon/mourn_coil.c"),this_object());
  if(!arg){
    
    set_light(1);
short_desc= (BOLD+BLK+"City of Qual'tor "+NORM+"("+RED+"RedTower"+NORM+")");
    long_desc=
     "Stone walls with a slight red tint to them line this area, which\n"+
     "is not really a room, but more a meeting place between several\n"+
     "corridors. The main hall runs north and east, while a small\n"+
     "room sits to the south.\n";

    items=({
     "wall","The red stone walls are the same as elsewhere in the tower",
     "corridor","The hallway runs east and north from here",
     "room","The small room to the south seems to be a storage area",
    });

    dest_dir=({
      "/players/daranath/qualtor/redtowr2.c","north",
      "/players/daranath/qualtor/redtowr4.c","south",
      "/players/daranath/qualtor/redtowr5.c","east",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("You find nothing within the area of interest.\n");
    say(tp +" searches the area.\n");
     return 1;
    }



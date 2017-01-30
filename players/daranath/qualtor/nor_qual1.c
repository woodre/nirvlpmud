#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
short_desc= (BOLD+BLK+"City of Qual'tor"+NORM+" (Northern Fields)");
    long_desc=
     "North of the ruined city of Qual'tor, a sparse pathway leads into\n"+
     "the city, as well as north torwards the mountain. Tall reeds grow\n"+
     "upon the eastern side of the pathway, blocking your view in that\n"+
     "direction, except for a small trail that leads east from\n"+
     "here. The entrance to Qual'tor lies south.\n";

    items=({
     "city","The city of Qual'tor lies in blackened ruins",
     "pathway","A rocky path leads north and south from here",
     "reeds","The tall reeds black your view to the east. It looks as if\n"+
             "some kind of swamp rises in that direction",
     "entrance","The northern gate of Qual'tor lies to the south",
    });

    dest_dir=({
      "/players/daranath/qualtor/nor_qual2.c","north",
      "/players/daranath/qualtor/north_gate1.c","south",
      "/players/daranath/outside/field1.c","east",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("You find nothing looking out from the reeds.\n");
    say(tp +" searches the area.\n");
     return 1;
    }


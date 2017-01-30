#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
 if(!present("tungus"))
move_object(clone_object("/players/daranath/qualtor/mon/tungus.c"),this_object());
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(Arena Ward)");
    long_desc=
"               "+BOLD+"Falcon Lane"+NORM+" (east, west)\n"+
   "North Road runs east and west here, the old boundry that marked the northern\n"+
   "edge of the city. No more, for the city grew around the north road and\n"+
   "completly enveloped it.\n";

    items=({
     "road","North road is made of a dark grey gravel",
     "darkness","The darkness hides many things",
    });

    dest_dir=({
      "/players/daranath/qualtor/nor_road5.c","east",
      "/players/daranath/qualtor/nor_road3.c","west",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("A quick search of the North Road reveals nothing.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

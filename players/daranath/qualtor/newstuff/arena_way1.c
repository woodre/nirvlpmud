#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(Arena Ward)");
    long_desc=
"               "+BOLD+"Arena Pathway"+NORM+" (north, south)\n"+
"The pathway leading to the Arena is only partially cleared, large chunks\n"+
"of stone and rubble are cast about the ancient roadway.  The ruins of\n"+
"the arena itself are just to the northeast, while the main body of the\n"+
"city is south and west from your position.\n";

    items=({
"pathway","The dirt pathway leading to the former arena is in unkempt shape",
"dirt","The dirt is a mixture of light brown and dark grey in color",
"stone","The stone is dark grey in color",
"rubble","Chunks of stone are strewn about the ancient roadway",
"roadway","The old roadway has been covered in years of dirt and debris, leaving only\n"+
     "a small pathway",
"city","The city of Qual'tor lies southwest from the Arena pathway",
    });

    dest_dir=({
  "/players/daranath/qualtor/newstuff/arena_way2.c","north",
  "/players/daranath/qualtor/newstuff/triumph2.c","south",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("A quick search of the Arena Pathway reveals nothing.\n");
    say(tp +" searches the area.\n");
     return 1;
    }


#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(Arena Ward)");
    long_desc=
"               "+BOLD+"Triumph Circle"+NORM+" (north, south)\n"+
"Triumph Circle begins here, leading from the old North road in Qual'tor\n"+
"and heading up and turning torwards the old Arena. On the days that contests\n"+
"contests would be held, this street would be filled with visitors from\n"+
"other cities and city-states.\n";

    items=({
"roadway","Triumph circle was a tough old dwarven built roadway and survived the warfare\n"+
     "from long ago",
"arena","The old arena that once sat to the northeast of here is currently in ruins",
"street","Triumph circle no longer holds visitors from other cities, just dust and debris",
"dust","The dust has settled here over time",
"debris","The debris from the ruins still can be seen strewn over the roadway",
"ruins","The city still lies in ruins for the most part, except for City Ward",
    });

    dest_dir=({
  "/players/daranath/qualtor/newstuff/triumph4.c","north",
  "/players/daranath/qualtor/nor_road3.c","south",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("A quick search of Triumph Circle reveals nothing.\n");
    say(tp +" searches the area.\n");
     return 1;
    }


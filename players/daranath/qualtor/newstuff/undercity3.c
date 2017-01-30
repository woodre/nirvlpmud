#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/newstuff/"
#include <ansi.h>

inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"("+BOLD+"UnderCity"+NORM+")");
    long_desc=
"               "+BOLD+"Under the City of Qual'tor"+NORM+"\n"+
"Large rocks and piles of rubble caused the sewer system to collapse\n"+
"and preventing any further travel northwards. Your only option is to\n"+
"follow the main tunnel back to the south.\n";

    items=({
"system","The old sewer system used to facilitate the waste removal needs of the city",
"rocks","Large rocks have collapsed the tunnel here",
"tunnel","This individual sewer tunnel has collapsed from falling rock from above",
"rubble","Smaller chunks of earth and rock form piles of rubble here",
"earth","Bits and pieces of the earth have fallen from above",
    });

    dest_dir=({
ROOT+"undercity2.c","south",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

search() {
write("A quick search of the sewers reveals little of interest.\n");
  say(tp +" searches the area.\n");
return 1;
}


#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(Arena Ward)");
    long_desc=
"               "+BOLD+"Triumph Circle"+NORM+" (east, west)\n"+
"The colorful banners and flags that used to decorate Triumph Circle\n"+
"are long since gone, taken from the city in the looting that accompanied\n"+
"Qual'tors downfall. \n";

    items=({
"banners","The colorful banners have long since been missing from Arena Ward",
"flags","The flags are missing from the arena",
"city","The city of Qual'tor is now being rebuilt by the remaining populace, starting\n"+
     "in City Ward and then maybe this area will get some attention",
"arena","The former arena of Qual'tor lies in ruins",
    });

    dest_dir=({
  "/players/daranath/qualtor/newstuff/triumph2.c","east",
  "/players/daranath/qualtor/newstuff/triumph4.c","west",
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


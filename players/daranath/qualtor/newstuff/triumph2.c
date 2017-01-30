#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(Arena Ward)");
    long_desc=
"               "+BOLD+"Arena Pathway"+NORM+" (north)\n"+
"               "+BOLD+"Triumph Circle"+NORM+" (west, south)\n"+
"Triumph Circle continues and winds its way to the west, while the\n"+
"pathway leading to Qual'tors old arena heads off northwards from here.\n"+
"With the city being reclaimed by the locals, regular work to clear and\n"+
"rebuild the roadway to the arena is a top priority.\n";

    items=({
"pathway","The dirt and gravel pathway leads northeast around the old arena",
"dirt","Dirt has been piled up over the years",
"gravel","Dark grey gravel was mixed in with the dirt on the pathway years ago",
"city","The city of Qual'tor is currently being rebuilt by its remaining populace",
"roadway","The roadway has not seen any work as of yet",
"arena","The former arena is a skeleton of its former self",
    });

    dest_dir=({
  "/players/daranath/qualtor/newstuff/arena_way1.c","north",
  "/players/daranath/qualtor/newstuff/triumph3.c","west",
  "/players/daranath/qualtor/newstuff/triumph1.c","south",
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


#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/newstuff/"
#include <ansi.h>
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(Arena Ward)");
    long_desc=
"               "+BOLD+"Triumph Circle"+NORM+" (north)\n"+
"               "+BOLD+"Griffin's Flight"+NORM+" (south)\n"+
"               "+BOLD+"Falcon Lane"+NORM+" (east)\n"+
     "North road twists and turns threw the city here, running both\n"+
     "east and slightly southwest. Griffin's Flight connects to North\n"+
     "Road from the south and it continues far into the city. Nothing\n"+
"else of note is about the area. A newly cleared roadway once \n"+
"again heads north from here.\n";

    items=({
     "statue","The large statue shows a gruesome scene of a group of gaurdsmen from\n"+
              "the city fought against many orcs, goblins, and ogres\n"+
              "while defending the city. It is quite impressive",
     "walkway","The walkway is made of stone and gravel",
    });

    dest_dir=({
  "/players/daranath/qualtor/newstuff/triumph5.c","north",
      "/players/daranath/qualtor/nor_road4.c","east",
      "/players/daranath/qualtor/grif_flight4.c","south",
    });

    }
  }

    init(){
      ::init();
add_action("search","search");
add_action("dar_south","south");
    }

    search(){
    write("A quick search of the North Road reveals nothing.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

dar_south() {
write("You leave the utter chaos of the area you are in and enter\n\n"+
      "               "+HIW+"City Ward"+NORM+"\n\n"+
      "You feel a sense of relief as you begin to relax a bit.\n\n");
return 0;
}


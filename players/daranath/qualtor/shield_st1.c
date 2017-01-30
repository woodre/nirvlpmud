#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/"
#include <ansi.h>
inherit "room/room";
int c;

reset(int arg){
if(!present("child")) {
 c = random(5);
if(c == 0) {move_object(clone_object(ROOT+"folk/chld_shadow.c"),this_object()); }
if(c == 1) {move_object(clone_object(ROOT+"folk/chld_light.c"),this_object()); }
if(c == 2) {move_object(clone_object(ROOT+"folk/chld_flame.c"),this_object()); }
if(c == 3) {move_object(clone_object(ROOT+"folk/chld_death.c"),this_object()); }
if(c == 4) {move_object(clone_object(ROOT+"newstuff/mon/chld_mind.c"),this_object()); }
}
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(City Ward)");
    long_desc=
"               "+BOLD+"Shield Street"+NORM+" (north, south)\n"+
"Shield Street runs north from the Merchant's Square, leading to\n"+
"the far end of Qual'tor. Once a great street, Shield street fell\n"+
"into ruins along with most of Qual'tor. Now, however, the street\n"+
"is in the process of being rebuilt, along with a good part of\n"+
"the city.\n";

    items=({
     "villa","The grand villas are abandoned and empty",
     "villas","The grand villas are abandoned and empty",
     "wall","The outer wall once lined the eastern side of shield street",
    });

    dest_dir=({
      "/players/daranath/qualtor/shield_st2.c","north",
      "/players/daranath/qualtor/east_road5.c","south",
/*
      "/players/daranath/qualtor/mansion/lot7.c","east",
*/
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("A quick search of Shield street reveals nothing.\n");
    say(tp +" searches the area.\n");
     return 1;
    }


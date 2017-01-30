#define ROOT "/players/daranath/qualtor/newstuff/"
#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
if(!present("gloom")) {
move_object(clone_object(ROOT+"mon/gloom_assassin.c"),this_object());
}
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(City Ward)");
    long_desc=
"               "+BOLD+"Shield Street"+NORM+" (north, south)\n"+
"               "+BOLD+"Dagger Alley"+NORM+" (west)\n"+
"Shield street continues north and south from here, along the outer\n"+
"wall of the city. The wall itself has been heavily patched up, trying to\n"+
"once again protect the populace from attack. \n";

    items=({
     "wall","The wall lies in ruins",
     "walls","The outer walls lie in ruins",
     "marks","Sorch marks look like magical damage to the city wall",
     "holes","Large holes make the outer wall look much like swiss cheese",
     "hole","Large holes make the outer wall look much like swiss cheese",
     "street","Shield street is made from stone and gravel",
    });

    dest_dir=({
      "/players/daranath/qualtor/shield_st4.c","north",
      "/players/daranath/qualtor/shield_st2.c","south",
/*
     "/players/daranath/qualtor/mansion/lot5.c","east",
     "/players/daranath/qualtor/mansion/lot6.c","west",
*/
  "/players/daranath/qualtor/dag_alley.c","west",
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


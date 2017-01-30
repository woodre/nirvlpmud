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
"               "+BOLD+"East Road"+NORM+" (east, west)\n"+
"The eastern road winds its way through the southern reaches of\n"+
"Qual'tor. The ruined buildings here have been knocked down, and\n"+
"new construction has started on both sides of the street. The\n"+
"road itself continues east and west.\n";

    items=({
     "road","East road is made of stone and gravel",
     "building","Each blackened building is a reminder of the struggle here",
     "buildings","The blackened buildings line the southern side of the\n"+
                 "street here, just like most of Qual'tor",
     "roadway","The roadway is made of stone and gravel",
    });

    dest_dir=({
/*
    "/players/maledicta/closed/sigils/mshop.c","south",
*/
      "/players/daranath/qualtor/east_road5.c","east",
      "/players/daranath/qualtor/east_road3.c","west",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("Searching the area brings signs of an intense struggle, confirmed\n"+
          "by the pool of blood left by the loser.\n");
    say(tp +" searches the area.\n");
     return 1;
    }



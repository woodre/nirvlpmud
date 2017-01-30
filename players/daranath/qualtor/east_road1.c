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
move_object(clone_object(ROOT+"folk/chld_light.c"),this_object());
  if(!arg){
    
    set_light(1);
short_desc= (BOLD+BLK+"City of Qual'tor "+NORM+"(City Ward)");
    long_desc=
"               "+BOLD+"East Road"+NORM+" (east, west)\n"+
     "The eastern path away from the central plaza of Qual'tor has\n"+
     "seen more rebuilding then any other road. Just to the south of\n"+
     "here an older shop seems to have survived the destruction of the\n"+
     "majority of the city. A small building sits on the northern side\n"+
     "of the road, this building also seems to be a shop of some sort.\n";

    items=({
     "road","East road is made of stone and gravel",
     "building","The new building is made of a dark rose colored wood",
     "shop","The shop sits to the south from here",
     "path","The walkway extends from the east to the west",
    });

    dest_dir=({
      "/players/daranath/qualtor/pawn_shop1.c","north",
      "/players/daranath/qualtor/east_road2.c","east",
      "/players/daranath/qualtor/newstuff/new_entry.c","west",
      "/players/daranath/qualtor/east_shop.c","south",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("A quick search of the East Road brings nothing of value.\n");
    say(tp +" searches the area.\n");
     return 1;
    }



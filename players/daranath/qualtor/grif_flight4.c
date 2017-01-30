#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/newstuff/"
#include <ansi.h>
inherit "room/room";

reset(int arg){
if(!present("paladin"))
move_object(clone_object(ROOT+"mon/paladin.c"),this_object());
if(!present("citymon")){
int a, b; a=0; b = (random(3)+1);
 while(a<b) {
 int c; c = random(3);
if(c == 0) move_object(clone_object(ROOT+"mon/dwarf_bar.c"),this_object());
if(c == 1) move_object(clone_object(ROOT+"mon/elf_bar.c"),this_object());
if(c == 2) move_object(clone_object(ROOT+"mon/half_bar.c"),this_object());
 a++; }
}
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(City Ward)");
    long_desc=
"               "+BOLD+"Griffin's Flight"+NORM+" (north, south)\n"+
"               "+BOLD+"North Road"+NORM+" (west)\n"+
     "Griffin's Flight continues from here, just to the east of the\n"+
     "former marketplace. Not much remains of the area around the market,\n"+
     "long ago tents and pavillions would be set up here selling\n"+
     "various objects and foodstuffs to the people. The empty road\n"+
     "runs north and south from here.\n";

    items=({
     "road","East road is made of stone and gravel",
     "ruins","The arena's ruins are a blackened and burnt out shell",
    });

    dest_dir=({
      "/players/daranath/qualtor/nor_road3.c","north",
      "/players/daranath/qualtor/grif_flight3.c","south",
  "/players/daranath/qualtor/nor_road2.c","west",
    });

    }
  }

    init(){
      ::init();
add_action("search","search");
add_action("dar_west","west");
    }

    search(){
    write("A quick search of the roadway brings nothing of value.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

dar_west() {
write("You climb over the strong barricade and head into\n\n"+
      "              "+WHT+"GHOST WARD"+NORM+"\n\n"+
      "You shiver as you see the dark ash falling from the sky.\n\n");
return 0;
}


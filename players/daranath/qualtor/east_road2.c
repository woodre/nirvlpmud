#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/"
#include <ansi.h>
inherit "room/room";
int c;

reset(int arg){
if(!present("guard")){
move_object(clone_object("/players/daranath/qualtor/folk/tguard1.c"),this_object());
}
if(!present("child")){
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
"               "+BOLD+"East Road"+NORM+" (northeast, west)\n"+
     "A large tavern stands on the northern side of the east road, a\n"+
     "wooden sign swinging slightly in the breeze out front. A large\n"+
"brand new building has recently been completed on the southern edge\n"+
"of the roadway. The front of the building is emblazoned with large\n"+
"red letters reading: "+HIR+"The Phoenix Inn"+NORM+".\n";

    items=({
     "road","East road is made of stone and gravel",
     "building","The blackened building across from the tavern has long\n"+
                "since been abandoned",
     "sign","The sign reads: The Black Rose Tavern",
     "tavern","The Black Rose Tavern is a new building within Qual'tor's ruins,\n"+
              "standing on the site of another former inn. The black\n"+
              "rose gets its name from the dark, rose tinted wood used\n"+
              "during its construction",
     "street","East road is made of stone and gravel",
    });

    dest_dir=({
      "/players/daranath/qualtor/black_rose.c","north",
"/players/daranath/qualtor/newstuff/pheonix.c","south",
      "/players/daranath/qualtor/east_road3.c","northeast",
      "/players/daranath/qualtor/east_road1.c","west",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("A quick search of the East Road shows many footprints leading south.\n");
    say(tp +" searches the area.\n");
     return 1;
    }


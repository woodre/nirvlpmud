#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/"
#include <ansi.h>

inherit "room/room";
int c;

reset(int arg){
if(!present("child")) {
 c = random(4);
if(c == 0) {move_object(clone_object(ROOT+"folk/chld_shadow.c"),this_object()); }
if(c == 1) {move_object(clone_object(ROOT+"folk/chld_light.c"),this_object()); }
if(c == 2) {move_object(clone_object(ROOT+"folk/chld_flame.c"),this_object()); }
if(c == 3) {move_object(clone_object(ROOT+"folk/chld_death.c"),this_object()); }
}
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(City Ward)");
    long_desc=
"               "+BOLD+"Market Pathway"+NORM+" (east, west)\n"+
"Several new buildings have been constructed here, including a small shop to\n"+
"the south and new stables north of this roadway. In the distance, you can\n"+
"see a couple of new shops standing around the new market square.\n"+
"The Qual'tor stables are located to the north, while a new trader is\n"+
"setting up shop on the southern edge of the roadway.\n";

    items=({
  "building","Several new building stand around Dar's new market",
  "buildings","Several new building stand around Dar's new market",
  "market","A new market has sprung up to the east from here",
  "square","The market square has a variety of new shops around it",
"market","The old stables are located along the northern edge of the roadway",
"trader","A small shop is being set up to the south by a dwarven trader",
  "road","The road is made of dirt and gravel",
  "roadway","The road is made of dirt and gravel",
    });

    dest_dir=({
"/players/daranath/qualtor/stable1.c","north",
ROOT+"newstuff/trader.c","south",
ROOT +"newstuff/market_path2.c","east",
"/players/daranath/qualtor/east_road5.c","west",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
add_action("dar_north","north");
add_action("dar_south","south");
    }

search() {
  write("Fresh footprints run all about the area, heading back and forth from the\n"+
        "new market to the ruins of Qual'tor.\n");
  say(tp +" searches the area.\n");
return 1;
}

dar_north() {
if(this_player()->query_level() > 5) {
write("The Qual'tor stables are a low level area, why not find something else\n"+
      "to kill, more suitable with your level.\n");
return 1; }
return 0;
}

dar_south() {
write("The "+BOLD+"Dwarven Trader"+NORM+" is still setting up shop.\nComing soon...\n");
return 1; 
}


#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/newstuff/"
#include <ansi.h>

inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(City Ward)");
    long_desc=
"               "+BOLD+"Market Pathway"+NORM+" (east, west)\n"+
 "The dirt and gravel roadway continues around the larger ruins of Qual'tor\n"+
 "leading to a new marketplace that has recently started to thrive.\n";

    items=({
  "building","Several new building stand around Dar's new market",
  "buildings","Several new building stand around Dar's new market",
  "market","A new market has sprung up to the east from here",
  "marketplace","A new marketplace has sprung up to the east from here",
  "square","The market square has a variety of new shops around it",
  "ruins","The ruins of Qual'tor are all around you",
  "road","The road is made of dirt and gravel",
  "roadway","The road is made of dirt and gravel",
    });

    dest_dir=({
ROOT +"marketsq.c","east",
ROOT +"market_path1.c","west",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

search() {
  write("Fresh footprints run all about the area, heading back and forth from the\n"+
        "new market to the ruins of Qual'tor.\n");
  say(tp +" searches the area.\n");
return 1;
}


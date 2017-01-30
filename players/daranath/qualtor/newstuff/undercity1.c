#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/newstuff/"
#include <ansi.h>

inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"("+BOLD+"UnderCity"+NORM+")");
    long_desc=
"               "+BOLD+"Under the City of Qual'tor"+NORM+"\n"+
"Dark stone walls flicker with a reflection of the sunlight filtering in\n"+
"from above. An old sewer line runs north and south from this position,\n"+
"the sewers themselves unused since Qual'tors initial downfall. A small\n"+
"amount of filthy water still runs along the sewer's midsection, but not\n"+
"enough to be of any use to the city.\n";

    items=({
"stone","Dark stone walls line the old sewer system",
"wall","The walls are made of a dark grey stone common in this area",
"walls","The walls are made of a dark grey stone common in this area",
"sunlight","A small amount of sunlight trickles in from the alley above\n"+
     "reflecting off the water and flickering along the dark walls",
"water","A very small amount of filthy water still rests in the old sewers.\n"+
     "Just enough to hide something in",
"sewer","The old Qual'tor sewer system used to extend beneath the entire\n"+
     "city. Now, from lack of maintenance and other nature causes,\n"+
     "the system has broken down and collapsed in many areas",
"line","The old sewer line still runs north and south from your area.\n"+
     "It looks stable enough to travel along, if you wish",
    });

    dest_dir=({
ROOT+"undercity2.c","north",
ROOT+"undercity6.c","south",
ROOT+"undercity4.c","east",
"/players/daranath/qualtor/scim_alley.c","up",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

search() {
write("A newly constructed tunnel runs to the east.\n");
  say(tp +" searches the area.\n");
return 1;
}


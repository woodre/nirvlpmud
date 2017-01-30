#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/newstuff/"
#include <ansi.h>

inherit "room/room";

reset(int arg){
if(!present("halfling")) {
move_object(clone_object(ROOT+"mon/half_fish.c"),this_object());
}
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"("+BOLD+"UnderCity"+NORM+")");
    long_desc=
"               "+BOLD+"Under the City of Qual'tor"+NORM+"\n"+
"The dark stone of the sewer system continues here, broken only by a\n"+
"small stone alcove upon the eastern ledge. Sewer tunnels run north\n"+
"and south, stable enough in both directions to travel.\n";

    items=({
"stone","The dark stone of the sewer line matches the stone found elsewhere under the\n"+
     "city of Qual'tor. It gives the city a distinct look",
"city","You are under the city of Qual'tor",
"system","The old sewer system used to facilitate the waste removal needs of the city",
"alcove","The dark alcove on the eastern ledge is a perfect spot to ambush from",
"ledge","A twin pair of ledges run along either side of the sewers themselves",
"sewer","The sewer tunnels are quite large and used to flush a good amount of waste",
"waste","The waste is gone, only a trickle of water runs through here",
"water","A trickle of water runs through the sewer lines now",
    });

    dest_dir=({
ROOT+"undercity3.c","north",
ROOT+"undercity1.c","south",
ROOT+"alcove.c","east",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

search() {
write("A quick search of the sewers reveals little of interest.\n");
  say(tp +" searches the area.\n");
return 1;
}


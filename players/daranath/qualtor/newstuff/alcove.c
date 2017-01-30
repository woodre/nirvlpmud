/* Future site of the Wolfen guild monster  (far future)    */

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
"The dark stone tunnels of Qual'tors former sewer system give way here,\n"+
"forming a small alcove set into the way. It is very shallow, probably\n"+
"once used as an ambush spot for unwarry passerbys\n";

    items=({
"stone","The stone is the same dark grey stone as the rest of Qual'tor",
"tunnel","The stone tunnels run throughout the undercity, made up of the former\n"+
     "sewer system that served Qual'tor before its downfall",
"tunnels","The stone tunnels run throughout the undercity, made up of the former\n"+
     "sewer system that served Qual'tor before its downfall",
"system","The sewer system was excavated during the height of the city. It is mostly\n"+
     "abandoned now, with only a trickle of water in the main lines",
"water","The dirty water runs in the sewer line to the west",
"line","The sewer lines run under the main city areas years ago",
"spot","The alcove is a perfect ambush spot for use against the unwary",
    });

    dest_dir=({
ROOT+"undercity2.c","west",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

search() {
write("Deep claw marks are found in the dark stone of the alcove.\n");
  say(tp +" searches the area.\n");
return 1;
}


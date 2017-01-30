#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/wastes/"
inherit "room/room";

reset(int arg){
  if(!arg){
    
set_light(1);
short_desc= (BLK+BOLD+"Gundar Plains"+NORM);
long_desc=
"The channel runs from the ancient roadway southwest along the dirt and rock of\n"+
"the Gundar plains. Earth and stone have been turned up and tossed aside, creating\n"+
"an even, almost smooth surface upon which to walk. The land has cooled for the\n"+
"most part, although some steam rises between cracks here and there.\n";

items=({
"channel","A wide channel has been cut from the earth years ago by the passage of lava",
"plains","The Gundar plains seemingly extend everywhere",
"earth","The lava that made the channel tore through the earth and stone here",
"stone","The lava that made the channel tore through the earth and stone here",
"land","The Gundar plains are ripped and torn about, making for a horrific scene",
"steam","The steam seems to suggest that not everything is quite cool yet",
"cracks","A variety of cracks in the land allow steam to pass through",
    });

    dest_dir=({
  ROOT+"west_road3.c","northeast",
  ROOT+"lava_entry.c","southwest",
    });

    }
  }

init(){
  ::init();
add_action("search","search");
}

search(){
write("The area seems rather devoid of life, years after the destruction passed through.\n");
  say(tp +" searches the area.\n");
 return 1;
}

realm() {return "NT"; }

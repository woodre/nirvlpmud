#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/wastes/"
inherit "room/room";

reset(int arg){
  if(!arg){
    
set_light(1);
short_desc= ("Entrance to the "+BLK+BOLD+"Gundar"+HIR+" Lava Pits"+NORM);
long_desc=
"The channel runs from the ancient roadway southwest along the dirt and rock of\n"+
"the Gundar plains. Earth and stone have been turned up and tossed aside, creating\n"+
"an even, almost smooth surface upon which to walk. The land has cooled for the\n"+
"most part, although you can see some red hot, glowing lava directly to\n"+
"your west.\n";

items=({
"earth","The lava that made the channel tore through the earth and stone here",
"stone","The lava that made the channel tore through the earth and stone here",
"surface","The channel has been cut into a remarkably smooth surface to walk",
"channel","The center of the channel is smooth, almost like a sidewalk",
"roadway","The roadway is back to the northwest",
"dirt","The Gundar plains are nothing but dirt and stone now",
"rock","The Gundar plains are nothing but dirt and stone now",
"plains","The Gundar plains extend as far as the eye can see",
"lava","To the west, some of the lava that created this channel has not cooled",
    });

    dest_dir=({
  ROOT+"west_road4.c","northeast",
  ROOT+"vapor4.c","south",
  ROOT+"lava1.c","west",
    });

    }
  }

init(){
  ::init();
add_action("search","search");
}

search(){
write("The farther west you search, the softer and warmer the land is\n");
  say(tp +" searches the area.\n");
 return 1;
}

realm() {return "NT"; }

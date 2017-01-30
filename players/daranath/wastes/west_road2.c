#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/wastes/"
inherit "room/room";

reset(int arg){
  if(!arg){
    
set_light(1);
short_desc= (BLK+BOLD+"Gundar Plains"+NORM);
long_desc=
"The temperature in the area rises steadily, as you procede westbound along\n"+
"the roadway. The surrounding landscape here us burnt and blackened, a massive\n"+
"firestorm having swept through here ages ago.\n";

items=({
"roadway","The roadway is in good shape, despite no working been done on it for decades",
"landscape","The landscape is the product of the magical accident that took Gundar out",
"land","The landscape is the product of the magical accident that took Gundar out",
"firestorm","The firestorm died out 30 years ago",
    });

    dest_dir=({
  ROOT+"west_road1.c","east",
  ROOT+"west_road3.c","west",
    });

    }
  }

init(){
  ::init();
add_action("search","search");
}

search(){
write("Ash still covers the ground around the roadway.\n");
  say(tp +" searches the area.\n");
 return 1;
}

realm() {return "NT"; }

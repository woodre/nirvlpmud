#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/wastes/"
inherit "room/room";

reset(int arg){
  if(!arg){
    
set_light(1);
short_desc= (BLK+BOLD+"Gundar"+HIR+" Lava Pits"+NORM);
long_desc=
"A large, stagnant pool of lava superheats the area here, making you start to \n"+
"sweat under your clothing and armor. A series of rocks float in place, making\n"+
"for an area you can explore. The floating rocks continue to the north and\n"+
"south of your location.\n";

items=({
"pool","A large pool of lava has settled here, but hasn't cooled over the years",
"lava","The lava never cooled down from the flow decades ago",
"rocks","Several rocks make for a pathway across the lava. They look stable enough to walk on",
"rock","Several rocks make for a pathway across the lava. They look stable enough to walk on",
    });

    dest_dir=({
  ROOT+"lava_entry.c","east",
  ROOT+"lava2.c","north",
  ROOT+"lava8.c","south",
    });

    }
  }

init(){
  ::init();
add_action("search","search");
}

search(){
write("The rocks seem to form a large pathway around the surface of the lava.\n"+
      "You believe you could walk about the lava upon the rocks.\n");
  say(tp +" searches the area.\n");
 return 1;
}

realm() {return "NT"; }

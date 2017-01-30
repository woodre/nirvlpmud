#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/wastes/"
inherit "room/room";

reset(int arg){
move_object(clone_object(ROOT+"mon/croaker.c"),this_object());
  if(!arg){
    
set_light(1);
short_desc= (BLK+BOLD+"Gundar Wastes"+NORM);
long_desc=
"The roadway continues to wrap itself around the boulder, heading north and \n"+
"south from your current location. Further along the road southwards, you can\n"+
"see where the roadway turns back east, having cleared the gigantic rock\n";

items=({
"road","The road continues north and south, alonside the gigantic boulder",
"roadway","The roadway continues north and south, alonside the gigantic boulder",
"boulder","The huge boulder sits east of your position, causing the roadway to\n"+
     "bend around it",
"rock","Yes, a boulder is also known as a large rock",
    });

    dest_dir=({
  ROOT+"east_path2.c","north",
  ROOT+"east_path4.c","south",
    });

    }
  }

init(){
  ::init();
add_action("search","search");
}

search(){
write("Nothing of interest is about the roadway here.\n");
  say(tp +" searches the area.\n");
 return 1;
}

realm() {return "NT"; }

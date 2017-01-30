#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/wastes/"
inherit "room/room";

reset(int arg){
if(!present("mephit")){
move_object(clone_object(ROOT+"mon/vapor_mephit.c"),this_object());
move_object(clone_object(ROOT+"mon/vapor_mephit.c"),this_object());
}
  if(!arg){
    
set_light(1);
short_desc= (BLK+BOLD+"Gundar "+BLU+"Vapor Springs"+NORM);
long_desc=
"Steam and vapor rising up through the larger cracks in the cooled lava flow\n"+
"have created a sauna-like atmosphere in this area. You begin to sweat and \n"+
"breathe heavily in your armor, and your weapondry seems to have doubled in\n"+
"weight. How can anything possibly live here.\n";

items=({
"steam","The steam and vapor are more intense here, increasing the uncomfortable temperatures",
"vapor","The steam and vapor are more intense here, increasing the uncomfortable temperatures",
"cracks","The cracks in the ground continue here, damage from the lava that ruined\n"+
         "this area in Gundar",
"lava","The lava in this area has cooled down on the surface",
    });

    dest_dir=({
  ROOT+"vapor4.c","west",
    });

    }
  }

init(){
  ::init();
add_action("search","search");
}

search(){
write("Nothing of interest is found around the cooled lava flow.\n");
  say(tp +" searches the area.\n");
 return 1;
}

realm() {return "NT"; }

#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/wastes/"
inherit "room/room";

reset(int arg){
if(!present("mephit")){
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
"steam","Hot steam and vapor rise up from the multitude of cracks in the ground",
"vapor","Hot steam and vapor rise up from the multitude of cracks in the ground",
"cracks","The ground is torn and cracked from the flow of lava in the area",
"sweat","I think you know what sweat looks like, you freak...",
"lava","The cooled lava flow allows you to walk upon its surface",
    });

    dest_dir=({
  ROOT+"lava_entry.c","north",
  ROOT+"vapor5.c","east",
    });

    }
  }

init(){
  ::init();
add_action("search","search");
}

search(){
write("You can see the hot lava through the various cracks in the ground.\n");
  say(tp +" searches the area.\n");
 return 1;
}

realm() {return "NT"; }

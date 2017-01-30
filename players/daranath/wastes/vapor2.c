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
"Vapor from the pools and springs obscures most of the area, slowing down travel\n"+
"through the area. The hot springs sit all around you, making the temperature\n"+
"well above normal. There must be some additional volcanic activity deep\n"+
"underground, keeping the springs warm.\n";

items=({
"vapor","Vapor and steam rise up from the various pools and springs here",
"steam","Vapor and steam rise up from the various pools and springs here",
"springs","The Gundar springs were formed after the volcanic activity superheated the\n"+
         "surrounding rock",
"underground","Its tough to look underground from here",
    });

    dest_dir=({
  ROOT+"vapor3.c","north",
  ROOT+"vapor1.c","east",
    });

    }
  }

init(){
  ::init();
add_action("search","search");
}

search(){
write("The Gundar vapor pools would be a great area to take a dip.\n");
write("If only they weren't so darn hot...\n");
  say(tp +" searches the area.\n");
 return 1;
}

realm() {return "NT"; }

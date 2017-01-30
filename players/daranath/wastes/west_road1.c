#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/wastes/"
inherit "room/room";

reset(int arg){
  if(!arg){
    
set_light(1);
short_desc= (BLK+BOLD+"Gundar Plains"+NORM);
long_desc=
"An ancient roadway leads westward, out of the rocky outcroppings that now \n"+
"plague Gundar. A few hills dot the landscape, which is otherwise devoid of\n"+
"life. The road seems to be in decent shape, despite noone living in Gundar\n"+
"for decades since the disaster.\n";

items=({
"hills","These hills used to house hundreds of halflings",
"roadway","The roadway was a main highway through Gundar at its prime",
    });

    dest_dir=({
  ROOT+"north_path1.c","east",
  ROOT+"west_road2.c","west",
    });

    }
  }

init(){
  ::init();
add_action("search","search");
}

search(){
write("Nothing about the roadway has changed for decades since the downfall of Gundar.\n");
  say(tp +" searches the area.\n");
 return 1;
}

realm() {return "NT"; }

#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/wastes/"
inherit "room/room";

reset(int arg){
move_object(clone_object(ROOT+"mon/goblin2.c"),this_object());
move_object(clone_object(ROOT+"mon/goblin2.c"),this_object());
  if(!arg){
    
set_light(1);
short_desc= (BLK+BOLD+"Gundar Wastes"+NORM);
long_desc=
"The trail in the rocky outcroppings turns here, heading off to the west. It\n"+
"still continues back to the south, but you can see some sort of cave mouth\n"+
"just to the west.\n";

items=({
"trail","The trail turns to the west here, while still leading south",
"outcroppings","The rocky outcroppings are everywhere within Gundar",
"rock","The rocky outcroppings are dark grey in color",
"rocks","The rocky outcroppings are dark grey in color",
"cave","A dark cave mouth stands in the rocky surface to the west of here\n"+
     "There seems to be a small wooden sign standing before the cave",
    });

    dest_dir=({
  ROOT+"north_path1.c","south",
  ROOT+"north_path3.c","west",
    });

    }
  }

init(){
  ::init();
add_action("search","search");
}

search(){
write("Goblin tracks continue here, leading to the west.\n");
  say(tp +" searches the area.\n");
 return 1;
}

realm() {return "NT"; }

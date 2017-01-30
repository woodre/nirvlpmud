#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/wastes/"
inherit "room/room";

reset(int arg){
  if(!arg){
    
set_light(1);
short_desc= (BLK+BOLD+"Gundar Wastes"+NORM);
long_desc=
"A trail that leads through a gap in the rocky mountain outcroppings leads\n"+
"both north and south through this area. A thin covering of sand sits on the\n"+
"trail itself, perhaps having fallen from above. An ancient roadway starts\n"+
"here and runs out to the west.\n";

items=({
"roadway","The roadway was a main highway through Gundar at its prime",
"trail","The trail continues north and south from here",
"sand","A then layer of sand covers the trail here",
"gap","A gap in the rocky outcroppings allows for the trail to run north",
"rock","The rocky outcroppings ease here, allowing passage several directions",
"rocks","The rocky outcroppings ease here, allowing passage several directions",
    });

    dest_dir=({
  ROOT+"north_path2.c","north",
  ROOT+"sub_entry.c","south",
  ROOT+"west_road1.c","west",
    });

    }
  }

init(){
  ::init();
add_action("search","search");
}

search(){
write("The sand is a light brown in color, definently not natural to this area.\n");
  say(tp +" searches the area.\n");
 return 1;
}

realm() {return "NT"; }


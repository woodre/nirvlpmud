#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/wastes/"
inherit "room/room";

reset(int arg){
  if(!arg){
    
set_light(1);
short_desc= (BLK+BOLD+"Gundar Wastes"+NORM);
long_desc=
"The small trail through the rocky wastes continue through this area, branching\n"+
"off to the east and west as well. The rocks themselves split in the three \n"+
"directions, allowing anyone to pass with ease. A small clearing can be seen\n"+
"to the west.\n";

items=({
"trail","The trail continue north and south, while extending east and west",
"rock","The rocky outcroppings ease here, allowing passage several directions",
"rocks","The rocky outcroppings ease here, allowing passage several directions",
"clearing","Looks like there might be a wagon in the clearing",
"wagon","Why not go west and check out the wagon",
    });

    dest_dir=({
  ROOT+"north_path1.c","north",
  ROOT+"entry.c","south",
  ROOT+"east_path1.c","east",
  ROOT+"merchant.c","west",
    });

    }
  }

init(){
  ::init();
add_action("search","search");
}

search(){
write("Wagon tracks lead into the clearing west of your position.\n");
  say(tp +" searches the area.\n");
 return 1;
}

realm() {return "NT"; }

#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/wastes/"
inherit "room/room";

reset(int arg){
move_object(clone_object(ROOT+"mon/goblin4.c"),this_object());
move_object(clone_object(ROOT+"mon/goblin4.c"),this_object());
move_object(clone_object(ROOT+"mon/goblin4.c"),this_object());
  if(!arg){
    
set_light(1);
short_desc= (BLK+BOLD+"Gundar Caves"+NORM);
long_desc=
"The largest and darkest of all the tunnels running from the main cave, this\n"+
"passage runs straight north and south into the mountain itself. The same fungus\n"+
"that grows elsewhere along the tunnels also has taken residence here, casting\n"+
"enough light so you can pick your way along the passage.\n";

items=({
"fungus","A softly glowing fungus gives off enough light to see by",
"passage","The rocky tunnel runs north and south",
"tunnel","The large tunnel leads between the two main caves of the complex",
"mountain","You are currently within the mountain",
"tunnels","The tunnels run throughout the complex",
"light","The light is shed by a strange fungus glowing upon the rock walls",
"walls","The natural rock walls are covered in a glowing fungus",
    });

    dest_dir=({
  ROOT+"cave_boss.c","north",
  ROOT+"caves_entry.c","south",
    });

    }
  }

init(){
  ::init();
add_action("search","search");
add_action("dar_north","north");
}

search(){
write("Larger footprints are mixed in with the goblin ones here.\n");
  say(tp +" searches the area.\n");
 return 1;
}

dar_north(){
  if(present("goblin")) {
write("The goblin stands in your way, blocking further passage north.\n");
return 1; }
return 0;
}

realm() {return "NT"; }

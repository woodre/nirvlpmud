#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/wastes/"
inherit "room/room";

reset(int arg){
  if(!present("sign")) {
move_object(clone_object(ROOT+"obj/goblin_sign.c"),this_object());
}
move_object(clone_object(ROOT+"mon/goblin4.c"),this_object());
move_object(clone_object(ROOT+"mon/goblin1.c"),this_object());
move_object(clone_object(ROOT+"mon/goblin1.c"),this_object());
move_object(clone_object(ROOT+"mon/goblin1.c"),this_object());
  if(!arg){
    
set_light(1);
short_desc= ("Outside the "+BLK+BOLD+"Gundar Caves"+NORM);
long_desc=
"The gap in the rocky outcroppings ends here, the small pathway leading directly\n"+
"into a small cave. The cave itself looks completly natural, although not much\n"+
"light seems to penetrate within.\n";

items=({
"rock","The rocky outcroppings ease here, allowing passage several directions",
"rocks","The rocky outcroppings ease here, allowing passage several directions",
"trail","The trail ends here, turning itself into the small cave",
"cave","A dark cave sits upon the facing of a larger rocky outcropping",
"light","What sparse light exsists in the Gundar Wastes does not penetrate\n"+
     "deeply into the cave itself",
    });

    dest_dir=({
  ROOT+"north_path2.c","east",
  ROOT+"caves_entry.c","enter",
    });

    }
  }

init(){
  ::init();
add_action("search","search");
add_action("dar_enter","enter");
}

search(){
write("Goblin tracks run all about the area, mostly into and out from the cave.\n");
  say(tp +" searches the area.\n");
 return 1;
}

dar_enter(){
if(present("champion")){
write("The goblin champion stands before you, blocking your way into the cave.\n");
return 1; }
if(present("goblin") && (!present("champion"))){
write("\nThe small goblins scatter before you, allowing you access to the caves.\n\n");
}
return 0;
}

realm() {return "NT"; }

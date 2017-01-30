#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/wastes/"
inherit "room/room";

reset(int arg){
move_object(clone_object(ROOT+"mon/croaker.c"),this_object());
move_object(clone_object(ROOT+"mon/croaker.c"),this_object());
  if(!arg){
    
set_light(1);
short_desc= (BLK+BOLD+"Gundar Wastes"+NORM);
long_desc=
"The roadway bends to the south, encircling a giant boulder that sits in the\n"+
"way. The boulder itself looks different from the rest of the rock you have\n"+
"seen thus far, leading you to believe that it was placed here or possibly\n"+
"thrown here by a volcanic explosion.\n";

items=({
"road","A wide road leads south from here",
"road","A wide roadway leads south from here, bending around the boulder",
"boulder","A gigantic boulder sits immediatly to the east, block further travel\n"+
     "and making the roadway turn southwards",
"mountain","You view of the mountain is blocked by the boulder",
    });

    dest_dir=({
  ROOT+"east_path3.c","south",
  ROOT+"east_path1.c","west",
    });

    }
  }

init(){
  ::init();
add_action("search","search");
}

search(){
write("Nothing about the roadway seems to strike your interest.\n");
  say(tp +" searches the area.\n");
 return 1;
}

realm() {return "NT"; }

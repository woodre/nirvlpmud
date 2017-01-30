#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/wastes/"
inherit "room/room";

reset(int arg){
  if(!arg){
    
set_light(1);
short_desc= (BLK+BOLD+"Gundar Wastes"+NORM);
long_desc=
"The gap in the rocky outcroppings leading eastwards seems to open up the \n"+
"further east you go. Leaving the majority of rock and stone behind, a wide \n"+
"roadway seems to form here, leading to a great mountain in the distance.\n";

items=({
"gap","The gap you choose leads east",
"rock","The rocky outcroppings are more to the west, lessening to the east",
"rocks","The rocky outcroppings are more to the west, lessening to the east",
"stone","Most of the stone stays behind you to the west",
"road","A wide road leads east from here",
"roadway","A wide roadway leads east from here",
"mountain","Off to east, a large mountain looms on the horizon. Looking closely\n"+
     "it seems to be more a plateau then a mountain",
    });

    dest_dir=({
  ROOT+"east_path2.c","east",
  ROOT+"sub_entry.c","west",
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

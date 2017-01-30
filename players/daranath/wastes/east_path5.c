#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/wastes/"
inherit "room/room";

reset(int arg){
  if(!arg){
    
set_light(1);
short_desc= (BLK+BOLD+"Gundar Wastes"+NORM);
long_desc=
"The distance between youself and the Gundar plateau has been cut in half, \n"+
"while you travelled along the only roadway you have yet to find here. Directly\n"+
"east of here, you can see the base of the plateau itself, rising up into\n"+
"the clouds.\n";

items=({
"plateau","The Gundar Plateau rises up directly to the east of your position.\n"+
     "You cannot see the top of the plateau from here, you'll probably need\n"+
     "to climb up there and explore things a bit",
"road","The road leads directly to the plateau itself",
"roadway","The roadway leads directly to the plateau itself",
    });

    dest_dir=({
  ROOT+"plateau_base.c","east",
  ROOT+"east_path4.c","west",
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

#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/wastes/"
inherit "room/room";

reset(int arg){
move_object(clone_object(ROOT+"mon/centipede.c"),this_object());
move_object(clone_object(ROOT+"mon/centipede.c"),this_object());
  if(!arg){
    
set_light(1);
short_desc= (BLK+BOLD+"Gundar Plateau"+NORM);
long_desc=
"At the very top of the Gundar plateau, a large open expanse is before you, only\n"+
"broken up by the occasion boulder or outcropping of rock. A pathway seems to \n"+
"have been worn into the plateau's top, leading into a clearing east of your\n"+
"position, while the trail leads back down from here\n";

items=({
"plateau","You are at the top of the Gundar plateau",
"rock","Large rocks and boulder dot the top of the plateau, making for a maze-like\n"+
     "pathway around the area",
"boulders","Residual boulders sit from the last time a volcanic explosion rocked Gundar",
    });

    dest_dir=({
  ROOT+"plateau1.c","east",
  ROOT+"plateau_base.c","down",
    });

    }
  }

init(){
  ::init();
add_action("search","search");
}

search(){
write("Nothing of interest is found about the plateau's top.\n");
  say(tp +" searches the area.\n");
 return 1;
}

realm() {return "NT"; }

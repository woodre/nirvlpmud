#include "/players/languilen/closed/ansi.h"
#include "../paths.h"
inherit "room/room";

reset(arg) {
     if(arg) return;
     set_light(1);

     short_desc = "The FunHouse Lobby";
     long_desc =
"    Most parents just leave thier children to play here while they\n\
go on about thier 'grown up' business but sometimes they wait.  For\n\
those who do this room has been furnished with several comfy chairs.\n\
A small archway in the west wall has the neon words "+HIG+"Fun"+HIB+"house"+NORM+" Entrance\n\
glowing above it.  There is a door here marked 'exit' but there is no\n\
visible means of opening it from this side.\n";

     items = ({
     "chairs","These chairs are made of beanbags affixed upon a short, wide bases",
     "sign","It's big!  It's loud!  You know what to do!",
     "door","small and inconspicuous, it is only for those exiting from within",
     "archway","This serves as the entryway into the funhouse",
     });

     dest_dir = ({
          AREA+"inside.c","west",
     });

     if( !present("doorway") ){
         move_object(clone_object(DOORWAY),this_object());
     }

}

init(){
     ::init();
     add_action("listening","listen");
}

listening(){
     write("From inside can be heard the laughter of many playing children.\n");
     return 1;
}

realm(){ return "NT"; }

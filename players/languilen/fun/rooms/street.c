#include "/players/languilen/closed/ansi.h"
#include "../paths.h"
#define TPN this_player()->query_name()
#define TP this_player()
inherit "room/room";

reset(arg) {
     if(arg) return;
     set_light(1);

     short_desc = "The FunHouse Lobby";
     long_desc =
"    Most parents just leave thier children to play here while they\n\
go on about thier 'grown up' business but sometimes they wait.  For\n\
those who do this room has been furnished with several comfy chairs\n\
A small archway in the west wall has the neon words "+HIG+"Fun"+HIB+"house"+NORM+" Entrance\n\
glowing above it.  There is a door here marked 'exit' but it looks like\n\
it has been locked for some reason.\n";

     items = ({
     "street","It looks heavily traveled, like a main street, but there's nobody here",
     "sign","It's big!  It's loud!  You know what to do!",
     "door","It's one of those doors kids just plow through without thinking", 
     });

     dest_dir = ({
	AREA+"inside.c","enter",
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
     write("The street is silent, the only thing to hear is your own heart beating.\n");
     return 1;
}

realm(){ return "NT"; }

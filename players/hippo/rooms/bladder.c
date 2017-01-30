inherit "room/room";
#include "room.h"
#include "/players/hippo/bs.h"
int i;
object stone;
reset(arg) {
   if(arg) return;
   short_desc = "The urine bladder";
   long_desc = "You landed in the bladder, and you notice a lot of urine"+BS+
       "around here. You suppose Hippo has to go to the toilet, soon."+BS;
   if(!present("stone")){
   for(i=0;i<3;i++){
     move_object(clone_object("/players/hippo/c/stone.c"),this_object());
}
}
    dest_dir =
   ({
   "/players/hippo/rooms/kidney.c","up",
   "/room/jetty2.c","push",
    }) ;
    set_light(1) ;
}

init()  {
	::init();
add_action("push","push");
	}

push(){
say(this_player()->query_name()+" decided to leave with the urine."+BS);
move_object(this_player(),"/room/jetty2.c");
write("You decided to push the wand of the bladder. That made Hippo"+BS+
   "think that his bladder was full. He had to go to the toilet very"+BS+
   "soon. He could not wait until he was at the toilet. He just did"+BS+
   "it here."+BS);
command("look",this_player());
say(this_player()->query_name()+" arrives with the urine of Hippo!"+BS);
return 1;
}

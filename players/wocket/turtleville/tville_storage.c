#include "/players/wocket/closed/ansi.h"
#define PATH "/players/wocket/turtleville"
inherit "/players/wocket/std/tvroom.c";

reset(arg){
move_object(clone_object("/players/wocket/junk/balloon.c"),this_object());
if(arg) return;
move_object(clone_object("/players/wocket/turtleville/OBJ/shellshield.c"),this_object());
move_object(clone_object("/obj/rope.c"),this_object());  

  short_desc = HIG+"The Turtleville Storage"+NORM;
  long_desc = "   Storage of Items for Turtleville\n"+
              "This is a wiz only room.  If your a player\n"+
              "your in trouble.\n";  
  set_light(1);
   dest_dir = ({
  });
}


inherit "room/room";
#include "ex.h"
reset(arg){
   if(arg) return;
   short_desc="A winding road";
   long_desc= "	The mountain looms in the air far to your north and you\n"+
              "the forest far to your south.  To the northwest you see the\n"+
              "path lead into a formation of rocks.  You get the sense that\n"+
              "something powerful is hidden in those rocks.\n";
   set_light(1);
   dest_dir =
   ({
		Road+"roadnw","northwest",
		"/room/forest12","south",
   });
}

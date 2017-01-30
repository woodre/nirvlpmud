inherit "room/room";
#include "ex.h"
reset(arg){
   if(arg) return;
   short_desc="A winding road";
   long_desc= "	You are now in a huge rock formation.  Passages lead in\n"+
              "three directions.  To the southwest you see the passage\n"+
              "continue and to the northwest you see the passage open up.\n"+
              "To the southeast you see the passage open up into a plain.\n"+
              "You get a strong sense of magic coming from the northwest\n";
   set_light(1);
   dest_dir =
   ({
		Road+"roadn1","southeast",
                Road+"roadnw2","northwest",
                Road+"roadnwsw","southwest",
   });
}

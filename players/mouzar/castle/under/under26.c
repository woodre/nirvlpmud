#include "/obj/ansi.h"
inherit"/room/room";
int i;
reset(arg) {
if(!arg) {
  set_light(1);
  short_desc = "Drow city";
  long_desc = "This drow city is just undescrible.  The stalamites and the stalatites\n"+
              "have been turned into buildings.  The "+BLU+"blue"+NORM+" & "+RED+"red"+NORM+" farie fire puts an\n"+
              "eerie and evil glow over the city.  The chanting is continuous here.\n"+
              "adding to the evil of the city.\n" ;
  dest_dir = ({"/players/mouzar/castle/under/under28","north",
               "/players/mouzar/castle/under/under24","south",
	       "/players/mouzar/castle/under/under27","east",
               });
           }
} 

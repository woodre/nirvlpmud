#include "/players/fred/mages/defs.h"

inherit	"room/room";

reset(arg) { 
 if(!present("board")) {
   MO(CO("/players/fred/mages/obj/board"), TO);
 }
  if(!arg) {
  set_light(1);
  short_desc = "The Guild Haven";
  long_desc = 
   "A sort-of safe room, but not really.  There is no fighting\n"+
   "allowed here so you should be safe if you just want to sit around.\n";
  property = ({"NF", "NT", "NC"});
  dest_dir = ({"/players/fred/mages/rooms/advance", "south"});
  }
}

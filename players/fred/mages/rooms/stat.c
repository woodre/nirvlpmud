#include "/players/fred/mages/defs.h"

inherit "room/room";

reset(arg) { 
 if(!present("shade")) {
   MO(CO("/players/fred/mages/mon/shade"), TO); }
 if(!present("throne")){
   MO(CO("/players/fred/mages/obj/throne"), TO);}
  if(!arg) { set_light(1);
  short_desc = "The Grand Adept's Office";
  long_desc = "Here the Shade will teach Black Circle Mages all they need to know. \n"+
   "Don't piss him off, and don't attack him.\n";
  dest_dir = ({"/players/fred/mages/rooms/hall", "south"});}
}

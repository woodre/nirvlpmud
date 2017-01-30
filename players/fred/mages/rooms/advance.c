#include "/players/fred/mages/defs.h"

inherit "room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "The Meeting Room";
  long_desc = 
   "This is a large room with tall ceilings. Black Circles used to meet\n"+
   "here to talk about the days events and current news.\n";
   dest_dir = ({"/players/fred/mages/rooms/haven", "north",
                "/players/fred/mages/rooms/hall","west",    
                "/players/fred/mages/rooms/basement","down",
                "/players/fred/mages/rooms/practice","up",
                "/players/fred/mages/rooms/entrance", "south"});
  }
}

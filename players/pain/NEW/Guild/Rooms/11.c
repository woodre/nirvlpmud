inherit "room/room";
#include "/players/pain/NEW/Guild/Rooms/defs.h"

reset(arg) {
  if(arg) return;
    set_light(1);
    short_desc = " ";
    long_desc = 
            " \n"
    ;

 dest_dir = ({
	PATH+"12.c", "north",
	PATH+"14.c", "south",
	PATH+"13.c", "east",
	PATH+"15.c", "west",
	PATH+"16.c", "up",
	PATH+"6.c", "down",
 });


}

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
	PATH+"27.c", "north",
	PATH+"31.c", "south",
	PATH+"29.c", "east",
	PATH+"33.c", "west",
	PATH+"2.c", "up",
 });


}

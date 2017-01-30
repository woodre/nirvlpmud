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
	PATH+"17.c", "north",
	PATH+"18.c", "south",
	PATH+"19.c", "up",
	PATH+"11.c", "down",
 });


}

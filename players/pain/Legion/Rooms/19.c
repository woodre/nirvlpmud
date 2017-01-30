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
	PATH+"20.c", "east",
	PATH+"21.c", "west",
	PATH+"22.c", "up",
	PATH+"16.c", "down",
 });


}

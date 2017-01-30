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
	PATH+"7.c", "north",
	PATH+"9.c", "south",
	PATH+"8.c", "east",
	PATH+"10.c", "west",
	PATH+"11.c", "up",
	PATH+"2.c", "down",
 });


}

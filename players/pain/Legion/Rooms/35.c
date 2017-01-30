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
	PATH+"36.c", "east",
	PATH+"1.c", "west",
 });


}

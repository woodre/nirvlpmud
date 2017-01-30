inherit "/players/vertebraker/closed/std/room.c";
#include </players/mo/ansi.h>
reset(arg) {
   if(arg) return;
   set_light(1);
set_short(BOLD+"Kapi Spaceport"+NORM);
set_long("blah\n");

add_exit("/players/mo/space/rooms/splow/r51","north");
}

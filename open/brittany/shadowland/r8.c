inherit "/players/vertebraker/closed/std/room.c";
#include "/players/brittany/ansi"


reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("A room");
set_long("blah\n");

add_exit("/players/brittany/shadowland/rooms/r3","north");
add_exit("/players/brittany/shadowland/rooms/r7","west");
add_exit("/players/brittany/shadowland/rooms/r9","east");
}

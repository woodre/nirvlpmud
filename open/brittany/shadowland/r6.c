inherit "/players/vertebraker/closed/std/room.c";
#include "/players/brittany/ansi"


reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("A room");
set_long("blah\n");

add_exit("/players/brittany/shadowland/rooms/r2","north");
add_exit("/players/brittany/shadowland/rooms/r10","south");
add_exit("/players/brittany/shadowland/rooms/r5","west");
add_exit("/players/brittany/shadowland/rooms/r7","east");
}

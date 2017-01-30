inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("A room");
set_long("blah\n");

add_exit("/players/mo/space/rooms/splow/r14","north");
add_exit("/players/mo/space/rooms/splow/r40","south");
add_exit("/players/mo/space/rooms/splow/r29","west");
add_exit("/players/mo/space/rooms/splow/r31","east");
}

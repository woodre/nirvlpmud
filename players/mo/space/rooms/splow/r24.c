inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("A room");
set_long("blah\n");

add_exit("/players/mo/space/rooms/splow/r10","north");
add_exit("/players/mo/space/rooms/splow/r37","south");
add_exit("/players/mo/space/rooms/splow/r23","west");
add_exit("/players/mo/space/rooms/splow/r25","east");
}

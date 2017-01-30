inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("A room");
set_long("blah\n");

add_exit("/players/mo/space/rooms/splow/r13","north");
add_exit("/players/mo/space/rooms/splow/r39","south");
add_exit("/players/mo/space/rooms/splow/r28","west");
add_exit("/players/mo/space/rooms/splow/r30","east");
}

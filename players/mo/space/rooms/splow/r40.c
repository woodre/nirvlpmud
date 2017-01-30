inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("A room");
set_long("blah\n");

add_exit("/players/mo/space/rooms/splow/r30","north");
add_exit("/players/mo/space/rooms/splow/r39","west");
add_exit("/players/mo/space/rooms/splow/r41","east");
}

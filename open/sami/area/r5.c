inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("A room");
set_long("blah\n");

add_exit("/players/sami/area/carnival/room/r12","south");
add_exit("/players/sami/area/carnival/room/r4","west");
add_exit("/players/sami/area/carnival/room/r6","east");
}

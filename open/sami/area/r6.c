inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("A room");
set_long("blah\n");

add_exit("/players/sami/area/carnival/room/r5","west");
add_exit("/players/sami/area/carnival/room/r7","east");
}

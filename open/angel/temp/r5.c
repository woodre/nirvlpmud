inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("A room");
set_long("blah\n");

add_exit("/open/angel/temp/r8","south");
add_exit("/open/angel/temp/r4","west");
add_exit("/open/angel/temp/r6","east");
}

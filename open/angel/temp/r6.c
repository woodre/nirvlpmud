inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("A room");
set_long("blah\n");

add_exit("/open/angel/temp/r3","north");
add_exit("/open/angel/temp/r9","south");
add_exit("/open/angel/temp/r5","west");
add_exit("/open/angel/temp/r7","east");
}

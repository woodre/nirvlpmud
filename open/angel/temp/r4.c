inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("A room");
set_long("blah\n");

add_exit("/open/angel/temp/r1","north");
add_exit("/open/angel/temp/r5","east");
}

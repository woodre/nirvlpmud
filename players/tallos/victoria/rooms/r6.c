inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("A room");
set_long("blah\n");

add_exit("/players/tallos/victoria/rooms/r2","north");
add_exit("/players/tallos/victoria/rooms/r10","south");
add_exit("/players/tallos/victoria/rooms/r5","west");
add_exit("/players/tallos/victoria/rooms/r7","east");
}

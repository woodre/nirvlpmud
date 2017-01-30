inherit "/players/vertebraker/closed/std/room.c";
int shield;

reset(arg) {
   if(arg) return;
   set_light(1);
   
   set_short("A dimly lit forest");
   set_long(
      "You are in part of a dimly lit forest.\n" +
      "Trails lead north, south and west.\n\n" +
      "There is an inn here.\n\n");
   
   add_exit("/room/south/sforst4","north");
   add_exit("/room/south/sforst10","south");
   add_exit("/room/south/sshore1","west");
   add_exit("/players/tallos/7tigers/rooms/portalroom","inn");
   
   add_item("inn","The 7Tigers inn.\n");
}

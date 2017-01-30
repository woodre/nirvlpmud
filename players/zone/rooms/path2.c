inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Forest Path";
  long_desc = 
   "The shrubbery here is almost totaly covering the floor, the path is almost\n"+
   "oblitterated and the path is neigh invisible.\n";
  dest_dir = ({"players/zone/rooms/path3.c", "north",
               "players/zone/rooms/path1.c", "south",
               "players/zone/rooms/mushrooms.c", "west"});
  }
}

inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Dead End";
  long_desc = 
   "There is a rope here that leads down.\n";
  dest_dir = ({"players/zone/rooms/town2.c", "east",
               "players/zone/rooms/tree.c", "down"});
  }
}

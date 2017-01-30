inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Sea";
  long_desc = 
   "Sea.\n";
  dest_dir = ({"players/zone/rooms/gargantua.c", "north",
               "players/zone/rooms/mountain3.c", "south"});
  }
}

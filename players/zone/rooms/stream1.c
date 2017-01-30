inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Stream";
  long_desc = 
   "A nice stream.\n";
  dest_dir = ({"players/zone/rooms/boar.c", "north",
               "players/zone/rooms/stream.c", "south",
               "players/zone/rooms/stream1.c", "west"});
  }
}

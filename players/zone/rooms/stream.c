inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Stream";
  long_desc = 
   "This is a nice pleasent stream.\n";
  dest_dir = ({"players/zone/rooms/stream1.c", "north",
               "players/zone/rooms/brook.c", "south"});
  }
}

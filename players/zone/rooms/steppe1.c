inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "A cold steppe";
  long_desc = 
   "The steppe flattens out in to a river valley to the north.\n";
  dest_dir = ({"players/zone/rooms/rvalley.c", "north",
               "players/zone/rooms/steppe.c", "south"});
  }
}

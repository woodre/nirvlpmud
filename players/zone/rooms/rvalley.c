inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "River Valley";
  long_desc = 
   "Here is a fertile river valley.  The river is young and has a broad\n"
+ "flood plain.  The water is rich in silt, which deposits into soil.\n";
  dest_dir = ({"players/zone/rooms/monkey.c", "north",
               "players/zone/rooms/rvalley.c", "west",
               "players/zone/rooms/steppe1.c", "south"});
  }
}

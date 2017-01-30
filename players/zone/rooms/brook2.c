inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Babbling Brook";
  long_desc = 
   "A babbling brook tumbling through the rocks and soil.\n";
  dest_dir = ({"players/zone/rooms/brook1.c", "north",
               "players/zone/rooms/brook2.c", "south"});
  }
}

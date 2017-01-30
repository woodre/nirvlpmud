inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Walkway";
  long_desc = 
   "Walkway leading west and southeast.\n";
  dest_dir = ({"players/zone/rooms/town4.c", "west",
               "players/zone/rooms/town6.c", "southeast"});
  }
}

inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "A cold steppe";
  long_desc = 
   "A hilly windy cold rocky steppe.\n";
  dest_dir = ({"players/zone/rooms/steppe1.c", "north",
               "players/zone/rooms/steppe.c", "west",
               "players/zone/rooms/mountain.c", "east"});
  }
}

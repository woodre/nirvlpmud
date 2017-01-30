inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "A mountain path";
  long_desc = 
   "A wending mountain path.\n";
  dest_dir = ({"players/zone/rooms/circle.c", "south",
               "players/zone/rooms/steppe.c", "west",
               "players/zone/rooms/mountain1.c", "east"});
  }
}

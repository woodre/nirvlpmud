inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "A misty mountain";
  long_desc = 
   "A continuing mountain path.  to the far north east, you see an island.\n";
  dest_dir = ({"players/zone/rooms/ronin.c", "north",
               "players/zone/rooms/mountain.c", "west",
               "players/zone/rooms/tengu.c", "east"});
  }
}

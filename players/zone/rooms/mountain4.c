inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "A misty mountain";
  long_desc = 
   "A misty mountain path.\n";
  dest_dir = ({"players/zone/rooms/mountain3.c", "north",
               "players/zone/rooms/mountain4.c", "west"});
  }
}

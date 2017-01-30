inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
   short_desc = "Misty mountain path";
  long_desc = 
   "A misty mountain abutting a sea to the north.  Beyond the sea there is\n"
+ "an island.\n";
  dest_dir = ({"players/zone/rooms/island.c", "north",
               "players/zone/rooms/mountain2.c", "west",
               "players/zone/rooms/mountain4.c", "south"});
  }
}

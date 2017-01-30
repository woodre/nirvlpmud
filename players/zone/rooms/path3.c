inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Forest Trail";
  long_desc = 
   "The path disappears into the dense forest.  You notice a blaze\n"+
   "that leads north.\n";
  dest_dir = ({"players/zone/rooms/path4.c", "north",
	       "players/zone/rooms/path2.c", "south"});
  }
}

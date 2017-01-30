inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "crosswalks";
  long_desc = 
   "A major intersection in a small treetop town\n";
  dest_dir = ({"players/zone/rooms/town4.c", "north",
               "players/zone/rooms/town1.c", "south",
               "players/zone/rooms/town3.c", "west",
               "players/zone/rooms/pub.c", "east"});
  }
}

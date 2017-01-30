inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Landing";
  long_desc = 
   "Around a large specimen of a sequoya, perhaps 50 feet in radius, there\n"+
   "curves a sturdy set of stairs leading up to a treetop village.\n";
  dest_dir = ({"players/zone/rooms/tree.c", "northwest",
               "players/zone/rooms/stairs.c", "up"});
  }
}

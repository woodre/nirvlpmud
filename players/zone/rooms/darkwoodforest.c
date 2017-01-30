inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Dark woods";
  long_desc = 
   "This is a dark forest.  Light seems to be eaten by the canopy.  It seems\n"+
   "erie with the light that does filter down through the leaves.  Because\n"+
   "of the dense foliage, it is hard to see very far.\n";
  dest_dir = ({"players/zone/rooms/europe.c", "west",
               "players/zone/rooms/brook.c", "east"});
  }
}

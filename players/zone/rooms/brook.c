inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "A babbling brook";
  long_desc = 
   "A small brook twists through the forest floor.  I seems to be a nice,\n"+
   "peaceful brook.  It get larger to the north, as other brooks join it.\n";
  dest_dir = ({"players/zone/rooms/stream.c", "north",
               "players/zone/rooms/darkwoodforest.c", "west",
               "players/zone/rooms/brook1.c", "east"});
  }
}

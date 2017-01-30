inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Babbling brook";
  long_desc = 
   "A small brook travelling through the forest floor.\n";
  dest_dir = ({"players/zone/rooms/brook2.c", "south",
               "players/zone/rooms/brook.c", "west"});
  }
}

inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Walkway";
  long_desc = 
   "Pathway leading to the east and south.  The shop lies to the north.\n";
  dest_dir = ({"players/zone/rooms/shop.c", "north",
               "players/zone/rooms/town2.c", "south",
               "players/zone/rooms/town5.c", "east"});
  }
}

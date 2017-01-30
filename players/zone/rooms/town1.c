inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Pathway into town";
  long_desc = 
   "This is a walkway wending between the mighty broughs of the tree.\n";
  dest_dir = ({"players/zone/rooms/town2.c", "north",
               "players/zone/rooms/stairs.c", "south",
               "players/zone/rooms/town3.c", "west"});
  }
}

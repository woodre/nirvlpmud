inherit	"room/room";

reset(arg) { 
 if(!present("gargantua")) {
   move_object(clone_object("players/zone/monster/gargantua.c"), this_object());}
  if(!arg) {
  set_light(1);
  short_desc = "A overgrown island";
  long_desc = 
   "This is an island with dense vegetation.\n";
  dest_dir = ({"players/zone/rooms/island.c", "south",});
  }
}

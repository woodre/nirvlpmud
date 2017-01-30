inherit	"room/room";

reset(arg) { 
 if(!present("mushrooms")) {
   move_object(clone_object("players/zone/obj/mushrooms.c"), this_object());
 }
  if(!arg) {
  set_light(1);
  short_desc = "A dank, fetid offshoot of the path with a toppled tree.";
  long_desc = 
   "A dank disgusting dark turnoff from the road, who's only draw is that\n"+
   "there once was a majestic tree here, which was toppled when some large\n"+
   "creature passed through.  The top of the tree shelters the stump, and\n"+
   "the stump has a jagged heartwood.  You hear noises to the north.\n";
  no_exits = 1;
  property = ({"nf"});
  items = ({"mushroom",
             "Psychadelic spotted lavender magic 'shrooms MADE for TRIPping."});
  dest_dir = ({"players/zone/rooms/path2.c", "east",
               "players/zone/rooms/goblin.c", "north",
               "players/zone/rooms/lemming1.c", "trip"});
  }
}

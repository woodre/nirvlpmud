inherit	"room/room";

reset(arg) { 
 if(!present("goblin")) {
   move_object(clone_object("players/zone/monster/goblin.c"), this_object());
 }
 if(!present("goblin2")) {
   move_object(clone_object("players/zone/monster/goblin.c"), this_object());
 }
 if(!present("goblin3")) {
   move_object(clone_object("players/zone/monster/goblin1.c"), this_object());
 }
 if(!present("goblin4")) {
   move_object(clone_object("players/zone/monster/goblin.c"), this_object());
 }
  if(!arg) {
  set_light(1);
  short_desc = "Goblin hole";
  long_desc = 
"A slimy nich with gobbets of decomposing sludge strewn about.\n";
  dest_dir = ({"players/zone/rooms/mushrooms.c", "south"});
  }
}

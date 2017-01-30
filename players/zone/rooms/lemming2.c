inherit	"room/room";

reset(arg) { 
 if(!present("lemming")) {
   move_object(clone_object("players/zone/monster/lem2.c"), this_object());
 }
 if(!present("dog")) {
   move_object(clone_object("players/zone/monster/dog.c"), this_object());
 }
 if(!present("lemming4")) {
   move_object(clone_object("players/zone/monster/lem.c"), this_object());
 }
  if(!arg) {
  set_light(1);
  short_desc = "Lemming Maze";
  long_desc = 
"A maze occupies this room, with lemmings dropping from a trapdoor\n"+
"floating in mid air.  They run about to their doom, dragging with them\n"+
"some cuddly dogs, not like some brutes you have seen elsewere around here.\n";
  dest_dir = ({"players/zone/rooms/lemming1.c", "south",
               "players/zone/rooms/lemming3.c", "east"});
  }
}

inherit	"room/room";

reset(arg) { 
 if(!present("lemming")) {
   move_object(clone_object("players/zone/monster/lem.c"), this_object());
 }
 if(!present("lemming2")) {
   move_object(clone_object("players/zone/monster/lem.c"), this_object());
 }
 if(!present("lemming3")) {
   move_object(clone_object("players/zone/monster/lem.c"), this_object());
 }
 if(!present("lemming4")) {
   move_object(clone_object("players/zone/monster/lem.c"), this_object());
 }
  if(!arg) {
  set_light(1);
  short_desc = "Lemming Cliff";
  long_desc = 
"A granite cliff which is occupied by countless lemmings leaping to their\n"+
"doom.  brainless suckers aren't they? Bad trip,  perhaps\n"+
   "you should sleep it off perhaps.\n";
  dest_dir = ({"players/zone/rooms/lemming2.c", "north",
               "players/zone/rooms/mushrooms.c", "sleep"});
  }
}

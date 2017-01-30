inherit	"room/room";

reset(arg) { 
 if(!present("lemming")) {
   move_object(clone_object("players/zone/monster/lem.c"), this_object());
 }
 if(!present("lemming1")) {
   move_object(clone_object("players/zone/monster/lem.c"), this_object());
 }
 if(!present("lemming4")) {
   move_object(clone_object("players/zone/monster/lem.c"), this_object());
 }
  if(!arg) {
  set_light(1);
  short_desc = "Lemming pool";
  long_desc = 
"There is a pool where lemmings that have survived the other tow rooms\n"+
"come to rest and relax, before the run back out into the fray\n"+
"The room to the south will loop you back here because it's not done.\n";
  dest_dir = ({"players/zone/rooms/lemming2.c", "west",
               "players/zone/rooms/lemming3.c", "south"});
  }
}

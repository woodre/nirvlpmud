inherit	"room/room";

reset(arg) { 
 if(!present("ronin")) {
   move_object(clone_object("players/zone/monster/ronin.c"), this_object());}
  if(!arg) {
  set_light(1);
  short_desc = "A mountain path";
  long_desc = 
   "A wending mountain path.";
  dest_dir = ({"players/zone/rooms/mountain2.c", "north",
               "players/zone/rooms/mountain1.c", "south"});
  }
}

inherit	"room/room";

reset(arg) { 
 if(!present("slime")) {
   move_object(clone_object("players/zone/monster/greenslime.c"), this_object());
 }
  if(!arg) {
  set_light(0);
  short_desc = "A slimy decaying room.";
  long_desc = 
   "The rooms seems to be covered with a slimy green substance.  There is a\n"+
   "archway to the east covered over with a cloth bearing many fetishes and\n"+
   "sigals.\n";
  dest_dir = ({"players/zone/rooms/guardian.c", "up",
               "players/zone/rooms/wraith.c", "east"});
  }
}

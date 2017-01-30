inherit	"room/room";

reset(arg) { 
if(!present("guardian")) {
  move_object(clone_object("players/zone/monster/guardian.c"), this_object());}
  if(!arg) {
  set_light(1);
short_desc = "Entrance to an ancient barrow\n";
  long_desc = 
"This is an entrance to an ancient barrow set in a hill.  The glypns on the\n"+
"menheirs supporting the entrance seem to tell, as far as you can interpret\n"+
   "of an ancient king and his downfall.\n";
  dest_dir = ({"players/zone/rooms/circle.c", "north",
               "players/zone/rooms/slime.c", "down"});
  }
}

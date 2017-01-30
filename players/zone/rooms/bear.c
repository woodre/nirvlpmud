inherit	"room/room";

reset(arg) { 
 if(!present("bear")) {
   move_object(clone_object("players/zone/monster/bear.c"), this_object());
 }
  if(!arg) {
  set_light(0);
  short_desc = "Bear cave";
  long_desc = 
   "A rocky cave with bones and fur strewn about.  It looks to be a den of\n"+
   "some kind of animal.\n";
  dest_dir = ({"players/zone/rooms/bramble.c", "east"});
  }
}

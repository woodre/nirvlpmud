inherit	"room/room";

reset(arg) { 
 if(!present("wraith")) {
   move_object(clone_object("players/zone/monster/wraith.c"), this_object());
 }
  if(!arg) {
  set_light(0);
  short_desc = "A Barrow";
  long_desc = 
   "This is a barrow of an ancient king.  Little is know about them, but in\n"+
   "their time, it is said that they ruled with an iron fist and with\n"+
   "unnatural allies that are but now sleeping in barrows of their own.\n";
  dest_dir = ({"players/zone/rooms/slime.c", "west",});
  }
}

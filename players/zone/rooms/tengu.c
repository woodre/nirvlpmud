inherit	"room/room";

reset(arg) { 
 if(!present("tengu")) {
   move_object(clone_object("players/zone/monster/tengu.c"), this_object());}
  if(!arg) {
  set_light(1);
  short_desc = "A swampy den.";
  long_desc = 
   "This is a swampy area sometimes frequented by deamons locals call Tengus.\n";
  dest_dir = ({"players/zone/rooms/mountain1.c", "west",});
  }
}

inherit	"room/room";

reset(arg) { 
 if(!present("Boar")) {
   move_object(clone_object("players/zone/monster/boar.c"), this_object());
 }
  if(!arg) {
  set_light(1);
  short_desc = "Boar room";
  long_desc = 
   "Here is an area abundant with roots and other vegitation that boars love\n"+
   "to munch on.  The boars are legendary for their tenaciousness and ferocity\n"+
   "in battle.\n";
  dest_dir = ({"players/zone/rooms/stream1.c", "south"});
  }
}

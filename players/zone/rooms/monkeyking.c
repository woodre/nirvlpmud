inherit	"room/room";

reset(arg) { 
 if(!present("monkeyking")) {
   move_object(clone_object("players/zone/monster/monkeyking.c"), this_object());}
  if(!arg) {
  set_light(1);
  short_desc = "A lighted cavern";
  long_desc = 
   "This is a cavern behind a waterfall.  There is a stream crossing the\n"+
   "front of the cave, joining with the waterfall basin.  There is a rock\n"+
   "bridge crossing the streem.  You see seated on a stone throne, a white\n"+
   "monkey.\n";
  dest_dir = ({"players/zone/rooms/monkey.c", "south",});
  }
}

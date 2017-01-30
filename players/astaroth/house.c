inherit        "room/room";
 
reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "The inside of the house.";
  long_desc = 
   "You get in the house and find it hasn't been made yet.\n"+
   "You decide that leaving is a good option since there is\n"+
   "nothing to do here.\n"+
   "\n";
  dest_dir = ({"players/astaroth/tractor", "out"});
  }
}

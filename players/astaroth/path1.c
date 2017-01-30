inherit        "room/room";
 
reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "A small east-west path";
  long_desc = 
   "This is a small east-west path with nothing uncommon about it.\n";
  dest_dir = ({"players/astaroth/tractor", "east",
               "players/astaroth/pubfront", "west"});
  }
}

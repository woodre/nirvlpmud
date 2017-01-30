inherit        "room/room";
 
reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "This is the junction of themes";
  long_desc = 
   "Each direction takes you to a different section of the.\n" +
   "castle.  I won't list what direction takes you where\n" +
   "because I'll be adding new sections in the future.\n" +
   "\n";
  dest_dir = ({"players/astaroth/entrance", "south",
               "players/astaroth/music1", "north",
               "players/astaroth/tractor", "west"});
  }
}


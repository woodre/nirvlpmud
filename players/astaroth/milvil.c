inherit        "room/room";
 
reset(arg) { 
 if(!present("milli")) {
   move_object(clone_object("players/astaroth/milli.c"), this_object());
 }
 if(!present("vanilli")) {
   move_object(clone_object("players/astaroth/vanilli.c"), this_object());
 }
  if(!arg) {
  set_light(1);
  short_desc = "It's lip synch time...";
  long_desc = 
   "You hear the music, but nobody is really singing here.\n"+
   "Yes, you guessed it, it's Milli Vanilli!  And boy are they\n"+
   "out of synch now...\n"+
   "\n";
  dest_dir = ({"players/astaroth/music3", "west",
               "players/astaroth/evmusic", "east"});
  }
}

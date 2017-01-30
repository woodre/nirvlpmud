inherit	"room/room";

reset(arg) { 
 if(!present("preacher")) {
   move_object(clone_object("players/astaroth/preacher.c"), this_object());
 }
  if(!arg) {
  set_light(1);
  short_desc = "The Nirvanna Chapel";
  long_desc = 
   "This is the Nirvanna wedding chapel.\n"+
   "Players come here in pairs when they decide they want\n"+
   "to be married to each other.  Have fun and understand\n"+
   "that death doesn't need to mean you part when it's\n"+
   "on the mud.  Death will surely come if you attack\n"+
   "this preacher though.  Probably in just one hit.\n"+
   "The moral of this is that if you are stupid enough"+
    "\n"+
   "to attack him and get killed instantly, don't be a"+
    "\n"+
   "total whiner like Godflesh, just admit that you were"+
   "\n"+
   "a dumbfuck that couldn't recognize a warning.\n";
  dest_dir = ({"players/astaroth/pubfront", "north"});
  }
}

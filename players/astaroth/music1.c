inherit        "room/room";
 
reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "The Halls of Music";
  long_desc = 
   "Welcome to the Halls of Music.  This section is filled with all sorts\n"+
   "of musical groups.  There may be some you have not heard of and some\n"+
   "you may wish you had never heard of.  I intend to be flexible with \n"+
   "this area, so if you have a group you'd like to see in here, send me\n"+
   "mail telling me stuff like the name of the group, the players in it,\n"+
   "what style of music they play, and other things that would be helpful.\n"+
   "You can even send a room description if you like, but don't go to \n"+
   "overkill.  If you send it, I'll try, but can't promise that you will\n"+
   "see it soon.\n"+
   "\n"+
   "You can either go north for some really bad music, east for some good\n"+
   "stuff, or wimp out, be square, and go back the way you came by going\n"+
   "south.        Have fun!\n";
  dest_dir = ({"players/astaroth/junct", "south",
               "players/astaroth/evmusic", "north",
               "players/astaroth/gdmusic", "east"});
  }
}

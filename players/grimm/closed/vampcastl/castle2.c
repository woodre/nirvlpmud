inherit "room/room";
int count;
realm() { return "NT"; }
int outdoorness;
reset(arg) {
  if(arg) 
   return;
short_desc="Castle Bridge";
long_desc="You step onto the bridge and as you walk you can feel the bridge\n"+
   "give a little.  It is obvious that the bridge is extremely old.  The\n"+
   "bridge is spanning an ugly, hideous moat, no telling what is living\n"+
   "inside it, but if i were you i would try to stay away from it.  To the\n"+
   "east is the entrance to the Castle of Malichi and far to the west you\n"+
   "can see the forest.  As you wonder whether or not to go on into the\n"+
   "castle you notice that a deep fog is surrounding it and seems to flow\n"+
   "from within.  You might also be able to go down..(*cringe*).\n",
items=({"moat","The moat seems to be extremely deep, but you can't really\n"+
        "see the bottom of it because the moat is very dark and murky",
   "fog","The fog is very thick and looms about 2 feet off the ground.  It\n"+
   "seems to originate from the castle"});
dest_dir=({"players/grimm/closed/vampcastl/castle1","west"});
set_light(0);
outdoorness = 4;
}
init() {
   count = 0;
   add_action("down","down");
   add_action("down","d",1);
   add_action("east","east");
   ::init();
}
down() {
   count += 1;
   if(count < 2) { write("You crouch down and sit on the bridge ready to\n"+
      "enter the moat.  This is your only warning!! It may be deadly!\n");
   return 1; }
   if(count>=2) {write("You lower yourself into the moat and find that\n"+
      "you can't keep yourself up.  As you keep sinking you wish that you\n"+
      "had never enter the moat!\n");
      this_player()->move_player("in the moat#players/grimm/closed/vampcastl/moat");
      count = 0;
   return 1; }
return 1; }
east() {
/*
   if("/obj/weather"->query_night()) {
      this_player()->move_player("east#players/grimm/closed/vampcastl/castle24");
      return 1; 
   }
*/
   if(!present("vamp cross",this_player()) ) {
     write("Foolish mortal!!!  Entering the castle of Malachi without protection\n");
     write("You'll surely die now fool!!!!!!\n");
     this_player()->move_player("east#players/grimm/closed/vampcastl/castle25");
     return 1;
   }
   this_player()->move_player("east#players/grimm/closed/vampcastl/castle3");
  return 1;
}

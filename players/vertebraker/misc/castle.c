#define NAME "The Castle of the Templars"
#define DEST "room/south/sshore1"
#define TP this_player()
#define TPRN TP->query_real_name()
string *betas;

id(str) { return str == "path" || str == "stables" || str == "castle"; }

short() 
{
   return NAME +"\nA path leads southwest to the Stables";
}

long(str) 
{
   if(str == "castle")
      write("This is the castle of the Templars.\n"+
      "It is a small castle with a single tower near the gate. The walls are\n"+
      "about 30 feet high and extend completely around the castle.\n"+
      "It is currently a time of peace and Templars are allowing visitors to\n"+
      "enter a limited region of the castle.\n");
   if(str == "path" || str == "stables")
      write("A dusty path leads to the stables of the Knights\n"+
      "Templar, where the horses roam, waiting for their masters.\n");
}

init() {
   add_action("enter","enter");
   add_action("southwest","southwest");
   add_action("southwest","stables");
}
reset(arg) 
{
   move_object(this_object(), DEST);
}

enter() 
{
   write("You enter the castle of the Templars.\n");
   this_player()->move_player(
      "into the castle of the Templars#players/boltar/templar/enter.c");
   return 1;
}

is_castle()
{
   return 1;
}

southwest()
{
      {
      write("You walk down the dusty path to the stables...\n\n");
      TP->move_player("down the path to the stables#/players/vertebraker/misc/s1");
      return 1;
   }
}
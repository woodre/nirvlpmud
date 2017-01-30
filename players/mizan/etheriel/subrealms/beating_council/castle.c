#include "/players/mizan/esc.h"

id(str) { return str == "hole"; }

short()
{
  return "A hole leading to the Caverns of Stupidity";
}

long()
{
  write("This appears to be a distortion in the continuum of the ether-muck\n"+
  "that is some sort of entrance to what appears to be a dark hole.\n"+
  "A voice says to you:\n\n"+
  "  'You had best be careful in here. If you enter you WILL die.\n\n"+
  
  "If you feel brave and stupid enough perhaps you are able to 'enter' here.\n");
}

init()
{
  add_action("enter","enter");
}

enter(str)
{
   if(this_player()->query_level() < 15)
   {
      write("This might not be a good idea for you. You sense that you might get killed in there.\n");
      return 1;
   }
   this_player()->move_player("into the hole#/players/mizan/etheriel/subrealms/beating_council/entrance.c");

   write_file("/players/mizan/logs/SUBREALM_BEATING_ROOM", (this_player()->query_real_name() + " has found the hole on " + ctime() + "\n"));   
   
   return 1;
}

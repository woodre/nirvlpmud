#include "/players/mizan/esc.h"

id(str) { return str == "warp"; }

short()
{
  return "A warp into a cavern";
}

long()
{
  write("This appears to be a distortion in the continuum of the ether-muck\n"+
  "that is some sort of entrance to a cavern somewhere else. As you look closer\n"+
  "a voice says to you:\n\n"+
  "  'You had best be careful in here. The Hydra is like the Vrock. It will\n"+
  "   kill quickly if awakened. Consider yourself warned, traveler...\n\n"+
  "If you feel brave and strong enough perhaps you are able to 'enter' here.\n");
}

reset()
{
  move_object(this_object(), "/players/mizan/etheriel/ROOMS/niall.c");
}

init()
{
  add_action("enter","enter");
}

enter(str)
{
   if(this_player()->query_level() < 12)
   {
      write("This might not be a good idea for you. You sense that you might get killed in there.\n");
      return 1;
   }
   this_player()->move_player("into the warp#/players/mizan/etheriel/subrealms/alchcave/entrance.c");

   write_file("/players/mizan/logs/SUBREALM_ALCHCAVE", (this_player()->query_real_name() + " has found the cave on " + ctime() + "\n"));   
   
   return 1;
}

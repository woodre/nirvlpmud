#include "/players/fred/ansi.h"
inherit "/obj/treasure";

reset (arg)
{
  set_id("summons");
  set_short(HIW+"A summons"+NORM);
  set_long(
     "  This is a court summons.  Maybe you should 'review' it.\n");
  set_value(1);
}

init()
{
  ::init();
  add_action("read_it_ho", "review");
} 

read_it_ho(str)
{
  if(!str) { write("Review what?\n"); return 1; }

  if(str == "summon" || str == "summons")
  {
    write("You unfold the papers and read the following:\n\n"+
          "  You are hearby required to appear in Court on the\n"+
          "  1st day of March, 2007, at the Harford County\n"+
          "  Courthouse.  The plaintiff, Fred McHaha, has brought\n"+
          "  forth a legal lawsuit against you for general mocking\n"+
          "  and taunting.  The plaintiff is seeking punitive\n"+
          "  damages for emotional stress in the amount of $2,000,000.\n\n"+
          "  Signed,\n\n"+
          "  Judge Anti-Excalibur Williams\n\n");
    return 1; 
  }
}


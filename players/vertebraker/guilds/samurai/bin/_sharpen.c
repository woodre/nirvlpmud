#include "../def.h"

cmd_sharpen(str)
{
  if(!str)
  {
    write("Sharpen what?\n");
    return 1;
  }
  else
  {
    object wep;
    
  if(TP->query_guild_rank() < 1) return 0;
  if(TP->query_ghost()) return 0;
    if(!(wep = present(str, TP)))
    {
      write("You don't have "+str+".\n");
    }
    else if(!wep->is_weapon())
    {
      write("That is not a weapon!\n");
    }
    else if(wep->query_broke())
    {
      write("That weapon is broken!\n");
    }
    else 
    {
      write("You hew "+wep->query_name()+" softly.\n");
      say(TP->QN+" softly hews "+wep->query_name()+".\n");
      wep->set_hits(1);
      wep->set_misses(1);
    }
    return 1;
  }
}

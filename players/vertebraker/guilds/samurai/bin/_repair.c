#include "../def.h"

cmd_repair(str)
{
  if(TP->query_guild_rank() < 1) return 0;
  if(!str)
  {
    write("Repair what?\n");
    return 1;
  }
  else
  {
    object wep;
    
  if(TP->query_ghost()) return 0;
    if(!(wep = present(str, TP)))
    {
      write("You don't have "+str+".\n");
    }
    else if(!wep->is_weapon())
    {
      write("That is not a weapon!\n");
    }
    else if(!wep->query_broke())
    {
      write("That weapon is not broken!\n");
    }
    else 
    {
      write("You repair "+wep->query_name()+".\n");
      say(TP->QN+" repairs "+wep->query_name()+".\n");
      if(wep->query_broke() == 7)
      {
        write(CYN+"You have repaired the most damaged of weapons.\n"+NORM);
      }
      wep->fix_weapon();
    }
    return 1;
  }
}

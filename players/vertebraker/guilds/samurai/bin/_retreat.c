#include "../def.h"

cmd_retreat()
{
  object atk;
  if(TP->query_guild_rank() < 3)
  {
    write("You must master your current skills first.\n");
    return 1;
  }
  if(this_player()->query_sp() < 20)
  {
    write("You need more energy. [20]\n");
    return 1;
  }
  if(!this_player()->query_attack())
  {
    write("You're not in battle.\n");
    return 1;
  }
  this_player()->add_sp(-20);
  write("You retreat from the battle!\n");
  say(TP->QN+" retreats from the battle!\n");
  while(atk = this_player()->query_attack())
  {
    this_player()->stop_fight();
    atk->stop_fight();
  }
  return 1;
} 

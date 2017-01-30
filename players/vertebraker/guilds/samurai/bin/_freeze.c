#include "../def.h"

cmd_freeze(str)
{
  object gob;
  object player;
  
  if(TP->query_guild_rank() < 11)
    return 0;
  
  if(!str) return 0;
  
  if(!(player = find_player(str)))
  {
    write("You don't see "+str+" online.\n");
  }
  else
  {
    if(player->query_guild_name() != "samurai")
    {
      write(str+" is not a Samurai.\n");
    }
    else
    {
      gob = present("gob", player);
      
      gob->set_frozen(1);
      write("You freeze "+capitalize(str)+".\n");
      command("id :freezes "+capitalize(str)+"'s powers!", TP);
    }
  }
  return 1;
}
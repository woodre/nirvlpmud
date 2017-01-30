#include "../def.h"

cmd_shame(str)
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
      
      write("You shame "+capitalize(str)+".\n");
      command("id :shames "+capitalize(str)+"!", TP);
      
      gob->add_shame(1);
      
      write("Current shame level: "+gob->query_shame()+"\n");
    }
  }
  return 1;
}
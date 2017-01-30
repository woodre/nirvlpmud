#include "../def.h"
cmd_unguild(str)
{
  if(this_player()->query_guild_rank() < 11)
    return 0;
  if(!str)
  {
    write("Unguild who?\n");
  }
  else
  {
    object ob;
    
    if(!(ob = find_player(str)))
    {
      write("You don't see \""+str+"\" online.\n");
    }
    else
    {
      if(ob->query_guild_name() != "samurai")
      {
        write("That is not a Samurai!\n");
      }
      else
      {
        command("leave_guild", ob);
        command("id :has booted "+capitalize(str)+" from the guild.", TP);
      }
    }
  }
  return 1;
}
      

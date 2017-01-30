#include "../def.h"

cmd_staredown(str)
{
  object atk;
  if(TP->query_ghost()) return 0;
  if(TP->query_guild_rank() < 5)
  {
    write("You must master your current skills first.\n");
    return 1;
  }
  if(!str)
  {
    atk = this_player()->query_attack();
  }
  else
    atk = present(str, environment(TP));
    
  if(!atk){
    write("You must select a target to staredown.\n");
    return 1;
  }
  
  if(TP->query_sp() < 50)
  {
    write("You need more energy. [50]\n");
    return 1;
  }
  
  TP->add_sp(-50);
  
  write("You stare "+HIK+"darkly"+NORM+" into "+
   atk->QN+"'s eyes.\n");
  say(TP->QN+" stares "+HIK+"darkly"+NORM+" into "+
    atk->QN+"'s eyes.\n");
    
  atk->run_away();
  if(environment(atk) == ENV(TP))
  {
    string *dd;
    string *exits;
     int s;
    dd = ENV(TP)->query_dest_dir();
    s = sizeof(dd);
    exits=({});
    s--;
    while(s > 0)
    {
      exits += ({ dd[s] });
      s -= 2;
     }
     s = sizeof(exits);
     {
       object obj;
       obj = clone_object(OBJDIR+"init");
        move_object(obj, atk);
        command("init", atk);
        destruct(obj);
     }
     while(s --)
    {
         command(exits[s], atk);
     }
   }
  return 1;
}

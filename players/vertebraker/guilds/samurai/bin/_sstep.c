
#include "../def.h"

cmd_sstep(str)
{
  object obj;
  
  if(TP->query_ghost()) return 0;
  if(TP->query_guild_rank() < 8){
    write("You have not mastered your current skills yet.\n");
    return 1;
  }
  if(!str){
    write("Step to who?\n");
    return 1;
  }
  
  obj = find_player(str);
  
  if(!(obj = find_player(str)))
  {
    write(str+" is not logged on.\n");
    return 1;
  }
  
  if(obj->query_guild_name() != "samurai")
  {
    write(obj->QN+" is not a Samurai!\n");
    return 1;
  }
  
  if(TP->query_sp() < 100)
  {
    write("You don't have enough energy. [100]\n");
    return 1;
  }
  
  if(!obj->query_attack() || !(obj->query_attack()->is_player()))
  {
    write(obj->QN+" is not fighting another player!\n");
    return 1;
  }
  
  if(ENV(obj)->realm()=="NT" || ENV(TP)->realm()=="NT")
  {
    write("A warping of space prohibits it.\n");
    return 1;
  }
  
  write("Ok.\n");
  TP->add_sp(-100);
  TP->move_player("X#"+file_name(ENV(obj)));
  return 1;
}

#include "../def.h"

cmd_recruit(str)
{
  if(TP->query_ghost()) return 0;
  if(TP->query_guild_rank() < 11)
  {
    write("You cannot recruit new members.\n");
    return 1;
  }
  
  else {
    object obj;
    obj = find_player(str);
    
    if(!obj) return 0;
    
    if(obj->query_guild_name())
    {
      write("They are already guilded!\n");
      return 1;
    }
    
    if(obj->query_real_name()=="guest")
    {
      write("no.\n");
      return 1;
    }
    
    if(obj->query_level() < 8)
    {
      write("They must obtain level 8!\n");
      return 1;
    }
    
    write("You invite "+obj->query_name()+" to join the Guild.\n");
    tell_object(obj, (string)TP->QN+" invites you to join the Samurai Guild.\n");
    {
      object m;
      
      m = clone_object(OBJDIR+"ask");
      move_object(m, obj);
      m->load_it(TP, obj);
    }
    return 1;
  }
}

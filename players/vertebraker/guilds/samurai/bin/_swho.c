#include "../def.h"

cmd_swho()
{
  object *us;
  int    s;
  
  s = sizeof(us = users());
  
  write(pad("",69,'-')+"\n");
  
  while(s --)
  {
    if(us[s] && ENV(us[s]))
    {
      if(us[s]->query_level() > 20 || us[s]->is_testchar())
      {
        continue;
      }
      write(" "+pad(us[s]->QN, 14)+pad(""+us[s]->query_level(), 2));
      if(us[s]->query_extra_level())
        write("+"+pad(""+us[s]->query_extra_level(),3));
      else
        write("    ");
      
      write("  "+ENV(us[s])->short()+"\n");
    }
  }
  write(pad("",69,'-')+"\n");
  return 1;
}
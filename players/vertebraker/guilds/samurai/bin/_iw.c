#include "../def.h"

cmd_iw()
{
  object *us;
  int    s;
  
  s=sizeof(us=users());
  
  write("\n");
  write(pad("",69,'~')+"\n");
  write("\t\t\tSAMURAI\n");
  write(pad("",69,'~')+"\n");
  write("\tName\t\tRank\tLocation\n");
  write(pad("",69,'~')+"\n");
  
  while(s--)
  {
    if(us[s] && ENV(us[s]) && us[s]->query_level() < 21 &&
      us[s]->query_guild_name()=="samurai")
    {
      write("\t"+pad(us[s]->QN,18)+us[s]->query_guild_rank()
      +"\t"+ENV(us[s])->short()+"\n");
    }
  }
  write(pad("",69,'~')+"\n");
  write("\n");
  return 1;
}

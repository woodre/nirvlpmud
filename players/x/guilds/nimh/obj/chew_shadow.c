#include "../x.h"

object shad;
string chewer;

void start_shadow(object ob)
{
 shadow(ob, 1);
 chewer = (string)TP->RN;
 shad = ob;
}

void end_shadow()
{
 shadow(shad, 0);
 destruct(TO);
}

status query_nimh_chewed()
{
 return 1;
}

string short()
{
 if(TP && (string)TP->query_guild_name() == GUILDNAME)
  return ((string)shad->short()+HIC+" [C:"+chewer+"]"+NORM);
 else
  return (string)shad->short();
}

void long()
{
 shad->long();

 if(TP && (string)TP->query_guild_name() == GUILDNAME)
  write(HIC+"It carries the mark of "+CAP(chewer)+"!\n"+NORM);
}

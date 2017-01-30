#include <ansi.h>

int main()
{
   int i, z, noobs;
   object *list;
   
   list = users();
   
   write(HIB);
   write(pad("\n",45,'~')+"\n");
   write(NORM+HIC+"     Name:\tLevel:\t  Guild:         \n"+NORM+HIB);
   write(NORM+HIB);
   write("[#]"+pad("",38, '~')+"[#]\n");
   write(NORM);
   
   for(i = 0, z = 0; i < sizeof(list); i++)
   {   
      if(!environment(list[i]) || (int)list[i]->query_level() > 19)
         continue;
      
      if(present("newbie_helper", list[i]) || (int)list[i]->query_level() < 8)
         {
         write("     "+HIW+pad((string)list[i]->query_name(),12)+NORM);
         
         ++z;
         
         if ((int)list[i]->query_pl_k() == 1 ||
               (int)list[i]->query_pl_k() == 3)
         write((int)list[i]->query_level() + "*\t");
         else
if((int)list[i]->query_level() < 8) write((int)list[i]->query_level() + HIC +"!"+NORM+"\t");
         else
            write((int)list[i]->query_level() + "\t");
         
         if (!list[i]->query_guild_name())
            write(pad("None",15));
         else
            write(pad(capitalize((string)list[i]->query_guild_name()),15));
         
         write("\n");
       }
   }
   if(!z)
      {
      write(
         HIB+"[#]  "+NORM+
         pad("No other Newbie Helpers logged in.",36)+
         NORM+HIB+"[#]\n");
   }
   
   write(HIB);
   write(HIB+"[#]"+pad("",38, '~')+"[#]\n"+NORM);
   write(NORM);
   write(HIC+"\t!"+NORM+" denotes a Newbie!\n");
   return 1;
}


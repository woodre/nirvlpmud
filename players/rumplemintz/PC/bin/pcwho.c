/* pcwho - Shows online members of the Player Channel, idle time, and environment short */

#include <ansi.h>

int pcwho(){
   int x;
   object *us;
   us = users();
   write(HIW+"Name           Idle              Location"+NORM+"\n");
   write(HIW+"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="+NORM+"\n");
   for(x=0; x<sizeof(us); x++){
      if(present("player_channel", us[x]) && us[x]->query_level() < 20){
         write(us[x]->query_name());
         if(strlen((string)us[x]->query_name()) < 8)
            write("\t\t");
         else
            write("\t");
         write("\b\b"+query_idle(us[x])/60+" min\t");
         write("\t");
         write(environment(us[x])->short());
         if((int)present("player_channel", us[x])->query_shush() == 1)
            write("{Shushed}");
         write("\n");
       }
   }
   return 1;
}

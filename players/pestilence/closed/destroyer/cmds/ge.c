#include "/players/pestilence/define.h"
main(str)
{
   int who;
   string what;
   object *us; int x;
   if(!str)
      {
      write("Emote What?\n");
      return 1;
   }
   if(sscanf(str,"%s",what) < 1)
      {
      write("Emote what?\n");
      return 1;
   }
write_file("/players/pestilence/closed/destroyer/log/armytell",""+HIW+"<"+YEL+"Army of Pestilence"+NORM+HIW+"> "+NORM+YEL+capitalize(this_player()->query_real_name())+""+NORM+WHT+" "+what+""+NORM+ctime()+NORM+"\n");
   us = users();
   for(x=0;x<sizeof(us);x++)
   {
      if(present("destroyer_ob",us[x]) && !(present("destroyer_ob",us[x])->query_muff()))
         {
tell_object(us[x],HIW+"<"+YEL+"Army Of Pestilence"+NORM+HIW+"> "+NORM+YEL+capitalize(this_player()->query_real_name())+NORM+""+WHT+" "+what+""+NORM+"\n");
       }
   }
   write("\n");
   return 1;
}

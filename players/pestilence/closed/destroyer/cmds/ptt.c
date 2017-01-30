#include "/players/pestilence/define.h"
main(str)
{
   int who;
   string what;
   object *us; int x;
   if(!str)
      {
      write("Say What?\n");
      return 1;
   }
   if(sscanf(str,"%s",what) < 1)
      {
      write("Say what?\n");
      return 1;
   }
 write_file("/players/pestilence/closed/destroyer/log/combotell",""+HIW+"<"+YEL+"Army of Pestilence"+NORM+HIW+"> "+NORM+YEL+capitalize(this_player()->query_real_name())+" grunts:"+NORM+WHT+" "+what+""+NORM+ctime()+NORM+"\n");
   us = users();
   for(x=0;x<sizeof(us);x++)
   {
      if(present("destroyer_ob",us[x]) && !(present("destroyer_ob",us[x])->query_muff()) || present("dknight_ob",us[x]))
         {
tell_object(us[x],HIW+"<"+YEL+"Army/"+HIR+"Order"+NORM+HIW+"> "+NORM+YEL+capitalize(this_player()->query_real_name())+" grunts:"+NORM+WHT+" "+what+""+NORM+"\n");
       }
   }
   write("\n");
   return 1;
}

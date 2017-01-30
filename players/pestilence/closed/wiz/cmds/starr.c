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
   us = users();
   for(x=0;x<sizeof(us);x++)
   {
      if(present("star_tattoo",us[x]) && !(present("star_tattoo",us[x])->query_muff()) || present("star_tattoo",us[x]))
         {
tell_object(us[x],HIW+"<"+YEL+"UNFUCKINCENSORED"+HIR+"Order"+NORM+HIW+"> "+NORM+HIK+capitalize(this_player()->query_real_name())+" says:"+NORM+HIK+" "+what+""+NORM+"\n");
       }
   }
   write("\n");
   return 1;
}

#include <ansi.h>
main(str)
{
   string who, what;
   object *us; int x;
   if(!str)
      {
      write("No.\n");
      return 1;
   }
   if(sscanf(str,"%s#%s",who,what) < 2)
      {
      write("No.\n");
      return 1;
   }
   us = users();
   for(x=0;x<sizeof(us);x++)
   {
      if(present("star_tattoo",us[x]) && !(present("star_tattoo",us[x])->query_muff()))
         {
         tell_object(us[x],YEL+"~*~"+NORM+BOLD+(who)+NORM+YEL+"~*~:"+NORM+" "+what+"\n");
       }
   }
   write("Okay.\n");
   return 1;
}

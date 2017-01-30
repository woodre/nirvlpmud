#include "/players/vital/closed/headers/vital.h"
#include <ansi.h>

main(str) {
   string who, what;
   object *us; int x;
   if(!str) {
       write("Nothing to say?\n");
       return 1;
   }
   if(sscanf(str,"%s %s",who,what) < 2)
      {
      write("Bah. You botched that.\n");
      return 1;
   }
   us = users();
   for(x=0;x<sizeof(us);x++)
   {
      if(present("star_tattoo",us[x]) && !(present("star_tattoo",us[x])->query_muff()))
         {
         tell_object(us[x],YEL+"~*~"+NORM+BOLD+CAP(who)+NORM+YEL+"~*~:"+NORM+" "+what+"\n");
       }
   }
   write("Okay.\n");
   return 1;
}

get_help()
{
  string help;
  help = "Syntax: echostar <Star Name> <message>";
  return help;
}

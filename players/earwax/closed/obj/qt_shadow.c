#include <ansi.h>

/*
I copied this from vital's, figured he was the original source of
the ones that are in so many directories now, so i cp'd it from there
heh, sorry vital :)
a shadow to disallow people from viewing my history
*/

#include "/players/vital/closed/headers/vital.h"
object qt;

init_qt_shadow(object q)
{
   qt = q;
   shadow(qt,1);
}

query_action_history()
{
    if (TP && qt && qt != TP)
      {
      tell_object(TP,
         "Intruder alert!\n"+
         "Earwax has been notified of your attempt to access restricted data.\n");
      write_file("/players/earwax/closed/log/qt.log",
         HIR+"["+NORM+"R/Data [QT]"+HIR+"]"+NORM+" ("+TPRN+" "+ctime()+")\n");
      tell_object(qt,
         HIR+"["+NORM+"Alert!"+HIR+"]"+NORM+"\n"+
         CAP(TPRN)+" tried to access your quicktyper history!\n");
      if ((int)TP->query_level() < 100)
        destruct(TP);
      return 1;
   }
   else qt->history();
   return 1;
}

shadowed() { return 1; }

query_info(x)
{
   if(TP && qt && ENV(qt) && ENV(qt) != TP)
    return;
  else qt->query_info(x);
}

#include <ansi.h>

/*
a shadow to disallow people from viewing my history
*/

#include "/players/vital/closed/headers/vital.h"
object qt;

init_qt_shadow(object q)
{
   qt = q;
   shadow(qt,1);
}

history()
{
   if(TP && qt && ENV(qt) && ENV(qt) != TP)
      {
      tell_object(TP,
         "Intruder alert!\n"+
         "Vital has been notified of your attempt to access restricted data.\n");
      write_file("/players/vital/log/qt.log",
         HIR+"["+NORM+"R/Data [QT]"+HIR+"]"+NORM+" ("+TPRN+" "+ctime()+")\n");
      tell_object(ENV(qt),
         HIR+"["+NORM+"Alert!"+HIR+"]"+NORM+"\n"+
         CAP(TPRN)+" tried to access your quicktyper history!\n");
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

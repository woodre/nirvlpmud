/*
a shadow to disallow people from viewing my history
*/

#include "../../define.h"
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
      if(TPRN != "boltar") {
      tell_object(TP,
         "Intruder alert!\n"+
         "Verte has been notified of your attempt to access restricted data.\n");
      write_file("/players/vertebraker/log/naughty.txt",
         HIR+"["+NORM+"R/Data [QT]"+HIR+"]"+NORM+" ("+TPRN+" "+ctime()+")\n");
      tell_object(ENV(qt),
         HIR+"["+NORM+"Alert!"+HIR+"]"+NORM+"\n"+
         CAP(TPRN)+" tried to access your quicktyper history!\n");
      if(TPRN == "jenny") destruct(TP);
      return 1;
   }
}
   else qt->history();
   return 1;
}

shadowed() { return 1; }

query_info(x)
{
   if(TP && qt && ENV(qt) && ENV(qt) != TP && TPRN != "boltar")
    return;
  else qt->query_info(x);
}

#include <ansi.h>

object qt;

init_qt_shadow(object q)
{
   qt = q;
   shadow(qt,1);
}

query_action_history()
{
   if (this_player() && qt && qt != this_player())
      {
      tell_object(this_player(),
         "Intruder alert!\n"+
         "Rumplemintz has been notified of your attempt to access restricted data.\n");
      write_file("/players/rumplemintz/closed/LOGS/qt.log",
         HIR+"["+NORM+"R/Data [QT]"+HIR+"]"+NORM+" ("+this_player()->query_real_name()+" "+ctime()+")\n");
      tell_object(qt,
         HIR+"["+NORM+"Alert!"+HIR+"]"+NORM+"\n"+
         capitalize(this_player()->query_real_name())+" tried to access your quicktyper history!\n");
      if ((int)this_player()->query_level() < 100)
         destruct(this_player());
      return 1;
   }
   else qt->history();
   return 1;
}

shadowed() { return 1; }

query_info(x)
{
   if(this_player() && qt && environment(qt) && environment(qt) != this_player())
      return;
   else qt->query_info(x);
}

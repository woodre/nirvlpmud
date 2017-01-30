/* quicktyper shadow to disallow people from viewing my history */

#include "../../define.h"
object qt;

init_qt_shadow(object q) {
  qt = q;
  shadow(qt,1);
}

history() {
  if(this_player() && qt && environment(qt) && environment(qt) != this_player()) {
    if(this_player()->query_real_name() != "boltar") {
      tell_object(TP, "Forbin has been notified of your attempt to access restricted data.\n");
      write_file("/players/forbin/closed/log/qt_access.txt", 
                 HIR+"["+NORM+"R/Data [QT]"+HIR+"]"+NORM+" ("+this_player()->query_real_name()+" "+ctime()+")\n");
      tell_object(environment(qt),
                  HIR+"["+NORM+"Alert!"+HIR+"]"+NORM+"\n"+
                  CAP(this_player()->query_real_name())+" tried to access your quicktyper history!\n");
        return 1;
    }
  }
  else qt->history();
    return 1;
}

shadowed() { return 1; }

query_info(x) {
  if(this_player() && qt && environment(qt) && 
     environment(qt) != this_player() && this_player()->query_real_name() != "boltar")
    return;
  else qt->query_info(x);
}

#include "/players/jenny/define.h"
main(str) {
   string who; int lev; object freak;
   if(!str || sscanf(str,"%s %d",who,lev) != 2) {
      notify_fail("Syntax: 'set_level <freak> <lev>'\n");
      return 0; }
   freak = find_player(who);
   if(!freak) {
      FAIL("Freak not logged on.\n");
      return 0; }
   freak->set_level(lev);
   command("save",freak);
   write("You raise "+freak->query_name()+" to the level of: "+BOLD+RED+lev+NORM+"\n");
   tell_object(freak,
      "\n"+BOLD+RED+TPN+NORM+" raises you to the level of: "+BOLD+RED+lev+NORM+"\n");
   return 1; }

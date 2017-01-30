#include "/players/jenny/define.h"
main(str) {
   string who; int xlev; object freak;
   if(!str || sscanf(str,"%s %d",who,xlev) != 2) {
      notify_fail("Syntax: 'set_xlevel <freak> <xlev>'\n");
      return 0; }
   freak = find_player(who);
   if(!freak) {
      notify_fail("Freak not logged on.\n");
      return 0; }
   freak->set_extra_level(xlev);
   command("save",freak);
   write("You give "+xlev+" extra levels to "+freak->query_name()+".\n");
   tell_object(freak,
      BOLD+RED+TPN+NORM+" gives you "+BOLD+RED+xlev+NORM+" extra levels.\n");
   return 1; }

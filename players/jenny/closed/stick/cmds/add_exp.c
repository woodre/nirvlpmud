#include "/players/jenny/define.h"
main(str) {
   string who; int exp; object freak;
   if(!str || sscanf(str,"%s %d",who,exp) != 2) {
      notify_fail("Syntax: 'add_exp <freak> <experience>'\n");
      return 0; }
   freak = find_player(who);
   if(!freak) {
      notify_fail("Freak not logged on.\n");
      return 0; }
   freak->add_exp(exp);
   command("save",freak);
   write("You give "+exp+" experience points to "+freak->query_name()+".\n");
   tell_object(freak,
      BOLD+RED+TPN+NORM+" gives you "+BOLD+RED+exp+NORM+" experience points.\n");
   return 1; }

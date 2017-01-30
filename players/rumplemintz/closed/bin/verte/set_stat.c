/* sets stat y to number z on player x */
#include "../std.h"
main(str) {
   string who, stat; int num; object freak;
   if(!str || sscanf(str,"%s %s %d",who,stat,num) != 3) {
      FAIL("Syntax: 'set_stat <freak> <stat> <num>'\n");
      return 0; }
   freak = find_player(who);
   if(!freak) {
      FAIL("Freak not logged on.\n");
      return 0; }
   freak->set_attrib(stat,num);
   command("save",freak);
   write("You set "+BOLD+who+NORM+"'s "+BOLD+stat+NORM+" to "+BOLD+num+NORM+".\n");
   tell_object(freak,
      BOLD+TPN+NORM+" sets your "+BOLD+stat+NORM+" to "+BOLD+num+NORM+".\n");
   return 1; }

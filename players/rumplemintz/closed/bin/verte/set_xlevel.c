/* used to set a player's xlvl */
#include "../std.h"
main(str) {
   string who; int xlev; object freak;
   if(!str || sscanf(str,"%s %d",who,xlev) != 2) {
      FAIL("Syntax: 'set_xlevel <freak> <xlev>'\n");
      return 0; }
   freak = find_player(who);
   if(!freak) {
      FAIL("Freak not logged on.\n");
      return 0; }
   freak->set_extra_level(xlev);
   command("save",freak);
   write("You give "+xlev+" extra levels to "+freak->QN+".\n");
   tell_object(freak,
      BOLD+TPN+NORM+" gives you "+BOLD+xlev+NORM+" extra levels.\n");
   return 1; }

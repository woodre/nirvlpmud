/* sets a player's level */
#include "../std.h"
main(str) {
   string who; int lev; object freak;
   if(!str || sscanf(str,"%s %d",who,lev) != 2) {
      FAIL("Syntax: 'set_level <freak> <lev>'\n");
      return 0; }
   freak = find_player(who);
   if(!freak) {
      FAIL("Freak not logged on.\n");
      return 0; }
   freak->set_level(lev);
   command("save",freak);
   write("\nYou raise "+freak->QN+" to the level of: "+BOLD+BLK+lev+NORM+"\n\n");
   tell_object(freak,
      "\n"+BOLD+TPN+NORM+" raises you to the level of: "+BOLD+BLK+lev+NORM+"\n\n");
   return 1; }

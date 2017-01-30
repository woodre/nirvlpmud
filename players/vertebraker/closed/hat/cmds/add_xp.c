/* adds xp to a player */
#include "../std.h"
main(str) {
   string who; int xp; object freak;
   if(!str || sscanf(str,"%s %d",who,xp) != 2) {
      FAIL("Syntax: 'add_xp <freak> <xp>'\n");
      return 0; }
   freak = find_player(who);
   if(!freak) {
      FAIL("Freak not logged on.\n");
      return 0; }
   freak->add_exp(xp);
   command("save",freak);
   write("You add "+xp+" experience points to "+freak->QN+".\n");
   tell_object(freak,
      BOLD+TPN+NORM+" adds "+BOLD+xp+NORM+" experience points to you.\n");
   return 1; }


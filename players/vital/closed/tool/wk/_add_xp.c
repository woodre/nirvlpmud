#include "/players/vital/closed/headers/vital.h"
#include <ansi.h>

main(str) {
   string who;
   int xp;
   object freak;
   if(!str || sscanf(str,"%s %d",who,xp) != 2) {
      notify_fail(get_help());
      return 0; }
   freak = find_player(who);
   if(!freak) {
      notify_fail("Freak not logged on.\n");
      return 0; }
   freak->add_exp(xp);
   command("save",freak);
   write("You add "+xp+" experience points to "+freak->QN+".\n");
   tell_object(freak,
      BOLD+TPN+NORM+" adds "+BOLD+xp+NORM+" experience points to you.\n");
   return 1;
}

get_help() {
    string help;
    help = "Syntax: add_xp <player> <xp>";
    return help;
}

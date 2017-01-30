#include "/players/plasma/define.h"

main(string str) {
   object who;
   
   who = find_player(str);
   if(!who) {
      write("Who?\n");
      return 1; }
   
   move_object(who,ENV(TP));
   tell_object(who,"You have been moved.\n");
   write("Done.\n");
   return 1; }

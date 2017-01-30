#include "/players/jenny/define.h"
#define USER ENV(TO);
main(str) {
   object freak;
   if(!str) return 0;
   freak = find_player(str);
   if(!freak) {
      notify_fail("Freak is not logged on.\n");
      return 0; }
   freak->heal_self(10000);
write("You heal "+freak->query_name()+"\n");
   tell_object(freak,BOLD+BLU+"\t\t...you have been full healed by "+TPN+"\n"+NORM);
   return 1; }

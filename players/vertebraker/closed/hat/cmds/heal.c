#include "../std.h"
main(str) {
   object freak;
   if(!str) return 0;
   freak = present(str, environment(TP));
   if(!freak || !living(freak))
   freak = find_living(str);
   if(!freak) {
      FAIL("Freak is not logged on.\n");
      return 0; }
   freak->heal_self(10000);
   write("You heal "+freak->QN+".\n");
   tell_object(freak,BOLD+BLK+"\t\t...your wounds heal all the way...\n"+NORM);
   return 1; }

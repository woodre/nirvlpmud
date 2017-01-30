/* moves a player to me */
#include "../std.h"
main(str) {
   object freak;
   if(!str) {
      FAIL("Syntax: 'trans <freak>'\n");
      return 0; }
   freak = find_living(str);
   if(!freak) {
      FAIL("Freak not logged on.\n");
      return 0; }
   tell_object(freak,
      BOLD+"\t....you have been magically teleported elsewhere....\n"+NORM);
   tell_room(ENV(freak),
      BOLD+"\nCrackling energy builds around "+freak->QN+", and "+subjective(freak)+" disappears.\n"+NORM, ({freak}));
   MO(freak,ENV(TP));
   if(freak && present(freak, environment(TP)))
   write(freak->QN+" has been summoned.\n");
   return 1; }

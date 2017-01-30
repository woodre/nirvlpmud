/* moves a player to me */
#include "/players/jenny/define.h"
main(str) {
   object freak;
   if(!str) {
      notify_fail("Syntax: 'trans <freak>'\n");
      return 0; }
   freak = find_player(str);
   if(!freak) {
      notify_fail("Freak not logged on.\n");
      return 0; }
   tell_object(freak,
      BOLD+"\nTwo HUGE hired goons walk into the room.\n"+
"They grab you by the arm and say 'Jenny wants to see you'.\n"+
"You are personally escorted to see Jenny.\n"+NORM);
   tell_room(ENV(freak),
      BOLD+"Two hired goons drag "+freak->query_name()+" off to see Jenny.\n"+NORM, ({freak}));
   MO(freak,ENV(TP));
   write(freak->query_name()+" has been summoned.\n");
   return 1; }

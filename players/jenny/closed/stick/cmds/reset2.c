#include "/players/jenny/define.h"
main(str) {
   object freak; int x;
   if(!str) {
      FAIL("Syntax: 'run_reset <freak>'\n");
      return 0; }
   freak = find_player(str);
   if(!freak) {
      FAIL("Freak not logged on.\n");
      return 0; }
   freak->set_heart_beat(1);
   if(freak->query_fight_area()) x = 1;
   freak->reset(1);
   if(x) freak->set_fight_area();
   freak->heart_beat();
   freak->recalc_carry();
   freak->recalc_quest();
   write("You reset "+CAP(str)+"'s heart beat, carry, and quest.\n");
   tell_object(freak,
      BOLD+"\t\t....a calming sensation spreads over you....\n"+NORM);
   return 1; }

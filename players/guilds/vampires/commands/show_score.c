/*
show_score.h
*/

#include "/players/eurale/defs.h"

/* -------- Display the score & help info for the fangs ---------- */
show_score() {
   TP->score();
   TP->score2();
   write("\nYou possess the vampire skill level of: ");
   if(TPGEXP >= 670) write(HIR+"NOSFERATU"+NORM+"\n");
   else if(TPGEXP == 669) write(BOLD+"NEOPHYTE"+NORM+"\n");
   else if(TPGEXP == 668) write(HIC+"ACOLYTE"+NORM+"\n");
   else if(TPGEXP == 667) write(BOLD+"NOVITIATE"+NORM+"\n");
   else if(TPGEXP == 666) write(HIG+"APPRENTICE"+NORM+"\n");
   write("Type '"+BOLD+"vhelp cult"+NORM+"' for Vampire information.\n");
   
   write(HIR+"Your blood energy level is: "+NORM);
  if(TPBPTS > 1250) write("GODLIKE\n");
   else if(TPBPTS > 1000 && TPBPTS <= 1250) write("UNBELIEVABLE\n");
   else if(TPBPTS > 750 && TPBPTS <= 1000) write("EXTREME\n");
   else if(TPBPTS > 550 && TPBPTS <= 750) write("HUGE\n");
   else if(TPBPTS > 450 && TPBPTS <= 550) write("ROBUST\n");
   else if(TPBPTS > 350 && TPBPTS <= 450) write("HIGH\n");
   else if(TPBPTS > 250 && TPBPTS <= 350) write("MEDIUM\n");
   else if(TPBPTS > 150 && TPBPTS <= 250) write("LOW\n");
   else if(TPBPTS > 50 && TPBPTS <= 150) write("ANEMIC\n");
   else if(TPBPTS <= 50) write("CRITICAL\n");
   return 1;
}

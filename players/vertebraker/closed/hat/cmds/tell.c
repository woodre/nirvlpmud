#define color GRN

/* spiffy new tell cmd */
#include "../std.h"
main(str) {
   string who, what; object freak;
   if(!str || sscanf(str,"%s %s",who,what) < 2) {
      FAIL("Syntax: 'tell <freak> <blurb>'\n");
      return 0; }
   who = LOWER(who);
   freak = find_player(who,1);
   if(!freak) {
      FAIL("No such freak logged on.\n");
      return 0; }
      if(freak->query_invis()) write(CAP(who)+" is invisible.\n");
   if(!freak->query_interactive()) write(CAP(who)+" is disconnected.\n");
   else if(query_idle(freak) > 120) write(CAP(who)+" is idle.\n");
   else if(in_editor(freak)) write(CAP(who)+" is editing.\n");
    freak->add_tellhistory(CAP(TPRN)+" >> "+HIC+what+NORM);
  write("You tell "+freak->query_name()+": "+HIC+what+NORM+"\n");

   freak->Replyer("vertebraker");
  tell_object(freak, HIC+"Vertebraker"+NORM+" "+BLU+">>"+NORM+" "+HIC+what+NORM+"\n");
   return 1;
}

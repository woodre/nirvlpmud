#include "/players/jenny/define.h"
main(str) {
   string who, what; object freak;
   if(!str || sscanf(str,"%s %s",who,what) < 2) {
      notify_fail("Syntax: 'tell <freak> <blurb>'\n");
      return 0; }
   freak = find_living(who);
   if(!freak) {
      notify_fail("No such freak logged on.\n");
      return 0; }
   tell_object(freak,BOLD+MAG+CAP(TPRN)+" tells you: "+YEL+what+NORM+"\n");
   write(BOLD+MAG+"You tell "+freak->query_name()+": "+YEL+what+NORM+"\n");
   return 1; }

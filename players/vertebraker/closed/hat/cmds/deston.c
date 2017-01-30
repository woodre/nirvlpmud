/* dests an object off a player */
#include "../std.h"
main(str) {
   string who, id; object freak, thing;
   if(!str || sscanf(str,"%s %s",who,id) != 2) {
      FAIL("Syntax: 'deston <freak> <id>'\n");
      return 0; }
   freak = find_living(who);
   if(!freak) {
      FAIL("Freak not logged on.\n");
      return 0; }
   thing = present(id,freak);
   if(!thing) {
      FAIL("Object does not exist.\n");
      return 0; }
   destruct(thing);
   freak->recalc_carry();
   write("You destruct a "+id+" from "+freak->QN+"'s inventory.\n");
   tell_object(freak,
      BOLD+"\t\t....something disappears from your inventory....\n"+NORM);
   return 1; }

/*
  emote.h
*/

#include "/players/eurale/defs.h"
#include "defs.h"

/* built in emoter */
emote(str) {
if(!str || MY_FANGS->query_in_a_form()) {
  write("Not in your present form I'm afraid.\n");
  return 1; }
tell_room(environment(TP),capitalize(TPRN)+" "+str+"\n");
return 1;
}

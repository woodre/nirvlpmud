/*
  quit.h
*/

#include "/players/eurale/defs.h"

/* -------- Quit command for the fangs (clean up) ---------- */
vamp_quit() {

if(PFANGS->query_levitating()) {
  write("You cannot quit while levitating.\n");
  return 1; }

if(PFANGS->query_wolf_obj()) {
  destruct(PFANGS->query_wolf_obj());
  FANGS->tell_my_room(
    capitalize(TPRN)+" dismisses "+TP->query_possessive()+" wolf.\n");
  }

PFANGS->dismiss_bat("bat");
/* Removed TP->quit(); and made it return 0; */
return 0;
}

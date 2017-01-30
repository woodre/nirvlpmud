/*
  quit.h
*/

#include "/players/eurale/defs.h"

/* -------- Quit command for the fangs (clean up) ---------- */
vamp_quit() {
if(EFANGS->query_servant_obj()) {
  destruct(EFANGS->query_servant_obj());
  tell_room(environment(TP),
    capitalize(TPRN)+" dismisses "+TP->query_possessive()+" servant.\n");
  }

if(EFANGS->query_wolf_obj()) {
  destruct(EFANGS->query_wolf_obj());
  tell_room(environment(TP),
    capitalize(TPRN)+" dismisses "+TP->query_possessive()+" wolf.\n");
  }

if(EFANGS->query_sneak_seconds() > 0) {
  EFANGS->set_sneak_seconds(0);
  if(TP->query_invis() > 0 && TPL < 21) TP->make_visible();
  write("You've changed back from wraith form to normal form.\n");
  tell_room(environment(TP),
    capitalize(TPRN)+" slowly fades into fview...\n");
  }

  EFANGS->dismiss_bat("bat");
  TP->quit();
  return 1;
}

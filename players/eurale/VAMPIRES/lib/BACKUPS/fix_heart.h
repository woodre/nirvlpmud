/*
  fix heat - restarts players/fangs heartbeats
*/

#include "/players/eurale/defs.h"

/* -------- Fix this player's title or their heart beat ---------- */
fix_heart(str) {

if(str == "heart" || str == "heartbeat" || str == "heart beat") {
if(TP->query_ghost()) {
  write("You are dead and cannot fix your heartbeat.\n");
  return 1; }

  TP->heart_beat();
  TP->set_heart_beat(1);
  FANGS->heart_beat();
  FANGS->set_heart_beat(1);
  write("Your "+BOLD+"HEARTBEAT"+NORM+" returns to a normal rhythm.\n");
return 1; }
}

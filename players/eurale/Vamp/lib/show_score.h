/*
  show_score.h
*/

#include "/players/eurale/defs.h"

/* -------- Display the score & help info for the fangs ---------- */
show_score() {
  TP->score();
  TP->score2();
  EFANGS->show_guild_stuff();
  return 1;
}

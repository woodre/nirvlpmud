/*
  show_score.h
*/

#include "defs.h"

/* -------- Display the score & help info for the fangs ---------- */
show_score() {
  MY_PLAYER->score();
  MY_PLAYER->score2();
  MY_FANGS->show_guild_stuff();
  return 1;
}

/*
  show_score.h
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* -------- Display the score & help info for the pouch ---------- */
show_score() {
  MY_PLAYER->score();
  MY_PLAYER->score2();
  MY_POUCH->show_guild_stuff();
  return 1;
}

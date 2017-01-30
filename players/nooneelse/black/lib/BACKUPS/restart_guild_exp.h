/*
  restart_guild_exp.h
*/

#include "defs.h"

/* -------- Restart your guild experience  ---------- */
restart_guild_exp(str) {
  int current_guild_exp;
  if (!str || !str=="guild exp") return 0;
  current_guild_exp = MY_GUILD_EXP;
  MY_PLAYER->add_guild_exp(- current_guild_exp);
  MY_PLAYER->add_guild_exp(666);
  write("Unfortunately you'll now have to go do all the tasks again.\n");
  return 1;
}

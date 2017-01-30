/*
  goto_guild.h
*/

#include "defs.h"

/* ------------ vboard: transport me to vamp training room ------------ */
goto_guild() {
  if (GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)!=GUILD_MASTER &&
      GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)!=GUILD_ASSISTANT)
    return 0;
  call_other(GUILD_TRAINING, "???");
  move_object(MY_PLAYER, GUILD_TRAINING);
  command("look at board", MY_PLAYER);
  return 1;
}

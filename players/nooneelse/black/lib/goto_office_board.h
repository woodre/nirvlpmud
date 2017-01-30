/*
  goto_office_board.h
*/

#include "defs.h"

/* ------------ vboard: transport me to vamp training room ------------ */
goto_office_board() {
  if (GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)!=GUILD_MASTER) return 0;
  call_other(GUILD_OFFICE_FLOOR_TOP, "???");
  move_object(MY_PLAYER, GUILD_OFFICE_FLOOR_TOP);
  command("look at board", MY_PLAYER);
  return 1;
}

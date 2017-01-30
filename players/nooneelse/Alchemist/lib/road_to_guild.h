/*
  road_to_guild.h
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* -------- Show the path to the guild hall ---------- */
drain_corpse(str) {
  if (MY_GUILD_RANK < 10) {
    write(NORM+CYN+"You can't use that abilitiy yet.\n"+NORM);
    return 1;
  }
  write(NORM+CYN);
  cat(ALCHEMIST_HELP+"road_home.hlp");
  write(NORM+"\n");
  return 1;
}

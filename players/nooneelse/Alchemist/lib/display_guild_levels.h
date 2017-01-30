/*
  display_guild_levels.h
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* --------------- Display the Alchemist Guild levels --------------- */
guild_help(str) {

  write(NORM+CYN);
  cat("/players/nooneelse/Alchemist/hlp/levels.hlp");
  write(NORM+"\n");
  return 1;
}

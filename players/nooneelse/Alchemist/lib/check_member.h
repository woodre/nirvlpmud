/*
  check_member.h
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* --------  Check player to see if they're on one of the alchemist lists ---- */
check_player(str) {

  if (!str) {
    write(NORM+CYN+"Enter the name you want to check on the members/former lists.\n"+NORM);
    return 1;
  }
  if (this_player()->query_real_name()!=ALCHEMIST_GUILD_MASTER) {
    write(NORM+CYN+"You can't use that abilitiy.\n"+NORM);
    return 1;
  }
  write(NORM+CYN+"From the member list:\n"+
        "   ");
  call_other(ALCHEMIST_CENTRAL, "find_member", str);
  write("\n"+NORM);

  write(NORM+CYN+"From the former member list:\n"+"   ");
  call_other(ALCHEMIST_PROHIBIT, "find_traitor", str);
  write("\n"+NORM);
/*
  write(NORM+CYN+"From the inactive & thus former member list:\n"+
        "   ");
  call_other(GUILD_HISTORY_HALL, "find_member", str);
  write("\n"+NORM);
*/
  return 1;
}

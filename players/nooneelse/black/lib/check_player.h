/*
  check_player.h
*/

#include "defs.h"

/* --------  Check player to see if they're on one of the vamp lists ---- */
check_player(str) {
  if (!str) {
    write("Enter the name you want to check the members/traitors list for.\n");
    return 1;
  }
  write("From the member list:\n"+
        "   ");
  call_other(GUILD_LOWER_HALL, "find_member", str);
  write("\n");
  write("From the former member list:\n"+
        "   ");
  call_other(GUILD_PROHIBIT, "find_traitor", str);
  write("\n");
  if (find_player(str)) {
    if (present("nooneelse vampire bite", find_player(str))) {
      write("Info from their bite\n");
      present("nooneelse vampire bite", find_player(str))->query_bite();
    }
    write("\n");
  }
  return 1;
}

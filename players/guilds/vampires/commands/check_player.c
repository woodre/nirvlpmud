/*
  check_player.h
*/

#include "/players/eurale/defs.h"

/* --------  Check player to see if they're on one of the vamp lists ---- */
check_player(str) {

if(TPL < 17 || TPGEXP < 669) {
  write("You don't have the skills for that spell yet.\n");
  return 1; }

if(!str) {
  write("What is the player name you want to check?\n");
  return 1; }

write("From the member list:\n"+
      "   ");
call_other(MEMBER, "find_member", str);
  write("\n");
  write("From the former member list:\n"+
        "   ");
call_other(TRAITOR, "find_traitor", str);
  write("\n");
  if (find_player(str)) {
    if (present("vampire bite", find_player(str))) {
      write("Info from their bite\n");
      present("vampire bite", find_player(str))->query_bite();
    }
    write("\n");
  }
  return 1;
}

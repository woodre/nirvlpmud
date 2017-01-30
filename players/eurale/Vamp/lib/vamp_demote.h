/*
  eyes_light.h
*/

#include "/players/eurale/defs.h"

/* -------- Make a light ---------- */
vamp_demote(str) {
object who;

if(!str) { write("Demote who?\n"); return 1; }
if(TPRN != ("eurale" || "magus")) {
  write("You do not have the authority for that spell.\n");
  return 1; }

who = find_player(str);
if(!who) { write("Not logged on...\n"); return 1; }

if(who->query_guild_exp() - 1 < 666) {
  write(capitalize(str)+" cannot be demoted further.\n");
  return 1; }

who->add_guild_exp(-1);
who->save_me();
write("You've just demoted "+capitalize(str)+".\n");
return 1;
}

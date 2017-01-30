/*
  show_whov.h
*/

#include "defs.h"

/* --------- modified Who (version v) -------- */
show_whov(str) {
  string player_list;
  int i;
  player_list=MY_FANGS->sort_list_of_players(users());

write(HIR+
"   Name        Gender   Level   Guild           Location\n"+NORM+
"___________________________________________________________________________\n"+
"\n");

  for (i = 0; i < sizeof(player_list); i++) {
    if (player_list[i]->query_level() < 21 ||
        (player_list[i]->query_invis() > 0 &&
         player_list[i]->query_level() < 21)) {
if(player_list[i]->query_pl_k() > 0) write("#  ");
else if(player_list[i]->query_invis() &&
  player_list[i]->query_level() < 20) { write("*  "); }
else write("   ");
write(LADJUST(player_list[i]->query_name(),12));
write(LADJUST(player_list[i]->query_gender_string(),6)+"  ");
write(LADJUST(player_list[i]->query_level()+" + "+
  player_list[i]->query_extra_level(),9));

if(!environment(player_list[i])) { write(""); }
if (environment(player_list[i]))
  write(LADJUST(player_list[i]->query_guild_name(),4)+"  ");
if (environment(player_list[i]) && environment(player_list[i])->short())
  write(LADJUST(environment(player_list[i])->short(),35)+NORM+"\n");
    }
  }
write(BOLD+"\n"+
"===========================================================================\n"+
"     # = player killer         * = invisible    \n"+NORM+"\n");
  return 1;
}

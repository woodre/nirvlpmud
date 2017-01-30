/*
  show_whov.h
*/

#include "/players/eurale/defs.h"

show_whov(str) {
  string player_list;
  int i;
  player_list = FANGS->sort_list_of_players(users());

if(TPBPTS < 1) {
  write("You lack the blood energy to do that.\n");
  return 1; }

PFANGS->add_BLOODPTS(-1);
write(HIR+
"   Name        Gender   Level   Guild         Location\n"+NORM+
"___________________________________________________________________________\n"+
"\n");

for(i = 0; i < sizeof(player_list); i++) {
if(player_list[i]->query_invis() < TPL) {
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
  if(!player_list[i]->query_guild_name()) write("      ");
    else write(LADJUST(player_list[i]->query_guild_name(),4)+"  ");
if (environment(player_list[i]) && environment(player_list[i])->short())
  write(LADJUST(environment(player_list[i])->short(),35)+NORM+"\n");
    }
  }
write(BOLD+"\n"+
"===========================================================================\n"+
"     # = player killer         * = invisible    \n"+NORM+"\n");
  return 1;
}

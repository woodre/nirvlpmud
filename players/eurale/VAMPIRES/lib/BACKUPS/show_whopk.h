/*
  who list showing PKers and those in PK areas
*/

#include "/players/eurale/defs.h"

show_whopk(str) {
  string player_list;
  int i;
  player_list = FANGS->sort_list_of_players(users());

if(TPBPTS < 1) {
  write("You lack the blood energy to do that.\n");
  return 1; }

if(!TP->query_pl_k()) {
  write(HIR+"Only vampires with PK set can use this ability.\n"+NORM);
  return 1; }

PFANGS->add_BLOODPTS(-1);
write(HIR+
"Lev      Name                Location\n"+NORM+
"___________________________________________________________________________\n"+
"\n");

for(i = 0; i < sizeof(player_list); i++) {
if((player_list[i]->query_pl_k() ||
 player_list[i]->query_fight_area()) && player_list[i]->query_level() < 20) {
  write(LADJUST(player_list[i]->query_level(),7));
  write(LADJUST(player_list[i]->query_name(),15));

  if(!environment(player_list[i])) { write(""); }
  if (environment(player_list[i]) && environment(player_list[i])->short())
    write(LADJUST(environment(player_list[i])->short(),45)+NORM+"\n");
  }
}
write(BOLD+"\n"+
"===========================================================================\n"+
"\n\n"+NORM);
return 1;
}

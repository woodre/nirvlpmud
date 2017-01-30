/*
  list_vampires.h
*/

#include "/players/eurale/defs.h"

/* -------- Friends ---------- */
show_vamps(arg) {
  string str, player_list;
  int i, j;

if(TPBPTS < 1) {
  write("You don't have the blood energy to do that.\n");
  return 1; }

PFANGS->add_BLOODPTS(-1);
player_list = FANGS->sort_list_of_players(users());
write("\n"+HIR+
  " Name       Level  Gender Status  Ears    Location"+NORM);

write("\n");
for (i = 0; i < sizeof(player_list); i++) {
  if(present("vampire fangs", player_list[i]) ||
     present("vampire bite", player_list[i])) {
      if(player_list[i]->query_invis() < TPL) {
      if(player_list[i]->query_invis()) write("*"); else write(" ");
      write(LADJUST(player_list[i]->query_real_name(),12));
      write(LADJUST(player_list[i]->query_level(),6));
      write(LADJUST(player_list[i]->query_gender_string(),6)+"  ");
      if (player_list[i]->query_real_name()=="nooneelse" ||
          player_list[i]->query_real_name()=="eurale")
            write(RED+" ~V~"+NORM);
      else if(present("vampire bite",player_list[i])) write(" ~:~");
      else write(" ~"+RED+"o"+NORM+"~");
      if(present("vampire fangs", player_list[i]) &&
          present("vampire fangs", player_list[i])->
            query_telepathy())
               write("   on ");
      else write("   off");
      if(player_list[i]->query_level() > 20) write("   Unknown");
      else write("   "+LADJUST(environment(player_list[i])->short(),35));
      write("\n");
      }
    }
}
write(HIR+
  "  ~o~ = Vampire     ~:~ = bitten by vampire     * = invisible\n"+NORM);
return 1;
}

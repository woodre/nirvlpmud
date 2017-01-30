#include "/players/eurale/defs.h"

show_vamps2(arg) {
  string str, player_list;
  int i, j;

if(TPRN != "eurale" && TPRN != "magus") {
  write("You cannot use that command!\n");
  return 1; }

player_list = FANGS->sort_list_of_players(users());
write(HIR+
    " Name       Blood   Gexp         Location\n"+NORM);

for (i = 0; i < sizeof(player_list); i++) {
if(present("vampire fangs",player_list[i])) {
    if(player_list[i]->query_invis()) write("*"); else write(" ");
      write(LADJUST(player_list[i]->query_real_name(),12));
write(LADJUST(present("vampire fangs",player_list[i])->query_BLOODPTS(),5));
        write("   "+player_list[i]->query_guild_exp());
        write("    ");
      if(environment(player_list[i]))
        write("~"+(file_name(environment(player_list[i]))));
        else write("<location unknown>");
      write("\n");
      }
}
write("\n"+HIR+
  "  Apprentice -> Novitiate -> Acolyte -> Neophyte -> Nosferatu\n\n"+NORM);
  return 1;
}

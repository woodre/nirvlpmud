/*
  fellows.h
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* --------- modified Who showing only Alchemists -------- */
show_whoa(str) {
  object obj, next_obj;
  string player_list, str1, tmp, tmp1;
  int i;

  player_list=MY_POUCH->sort_list_of_players(users());
  for (i = 0; i < sizeof(player_list); i++) {
    if (present("Alchemist Pouch", player_list[i]) &&
        player_list[i]->query_level() < 21 ||
        (player_list[i]->query_level() > 21 &&
         player_list[i]->query_invis() <= 0)) {
      if (player_list[i]->query_pl_k() > 0)
        write("#");
      else
        write(" ");
      if (player_list[i]->query_invis() > 0)
        write("@");
      else
        write(" ");
      write(LADJUST(player_list[i]->query_name(),16)+" ");
      write(LADJUST(player_list[i]->query_gender_string(),6)+" ");
      write(LADJUST(player_list[i]->query_level(),8)+" ");
      write("("+LADJUST(player_list[i]->query_extra_level(),2)+") ");
      if (environment(player_list[i]) && environment(player_list[i])->short())
        write(environment(player_list[i])->short()+" ");
      if (player_list[i]->query_fight_area())
        write(NORM+RED+"[PK area]"+NORM+"\n");
      else
        write("\n");
    }
  }
  write("\n# = playerkiller   @ = invisible\n\n");
  return 1;
}

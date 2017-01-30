/*
  list_vampires.h
*/

#include "defs.h"

/* -------- Friends ---------- */
list_vampires(arg) {
  string str, player_list;
  int i, j;
  player_list=MY_FANGS->sort_list_of_players(users());
  write("\n");
  if (arg=="l") {
    write(HIR+
      "Name       Level  Gender Status  Ears"+NORM);
    if (GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)==GUILD_MASTER ||
        GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)==GUILD_ASSISTANT)
      write(   "   "+HIR+"Location"+NORM);
  }
  else {
    write(HIR+"Name       Level  Gender  Status Ears"+NORM);
    if (GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)==GUILD_MASTER ||
        GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)==GUILD_ASSISTANT)
      write(HIR+"  Gexp    Location"+NORM);
  }
  write("\n");
  for (i = 0; i < sizeof(player_list); i++) {
    if (present("vampire fangs", player_list[i]) ||
         present("nooneelse vampire bite", player_list[i])) {
      if (player_list[i]->query_invis() > 0 &&
          player_list[i]->query_level() > 21)
        j=0; /* don't show wizards on the list if they're invis */
      else
        j = 1;
      if (GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)==GUILD_MASTER ||
          GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)==GUILD_ASSISTANT)
        j = 1;
      /* don't show that butthead mythos */
      if (player_list[i]->query_level() > 100) j=0;
      /* show this vamp */
      if (j) {
        if (player_list[i]->query_invis() > 0)
          if (player_list[i]->query_level() > MY_LEVEL)
write(LADJUST("("+capitalize(player_list[i]->query_name())+")",12));
          else
write(LADJUST("("+capitalize(player_list[i]->query_real_name())+")",12));
        else
      write(LADJUST(player_list[i]->query_real_name(),12));
      write(LADJUST(player_list[i]->query_level(),6));
        write(LADJUST(player_list[i]->query_gender_string(),6)+"  ");
        if (player_list[i]->query_real_name()=="nooneelse" ||
            player_list[i]->query_real_name()=="eurale" ||
            player_list[i]->query_real_name()=="magus")
           write(RED+" ~V~"+NORM);
        else
        if (GUILD_OFFICE_FLOOR_TOP->find_officer(player_list[i]->query_real_name())==GUILD_LIEUTENANT)
           write(" ~"+RED+"v"+NORM+"~");
        else
           write(" ~"+RED+"o"+NORM+"~");
/*
        if (present("vampire fangs", player_list[i])) write(" ~o~");
*/
        if (present("nooneelse vampire bite", player_list[i])) write(" ~:~");
        if (present("vampire fangs", player_list[i]) &&
            present("vampire fangs", player_list[i])->
              query_telepathy())
          write("   on ");
        else
          write("   off");
      if ((GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)==GUILD_MASTER ||
           GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)==GUILD_ASSISTANT) &&
          arg!="l") {
        write("   "+player_list[i]->query_guild_exp());
        write("    ");
        if (environment(player_list[i])) {
          str=0;
          sscanf(file_name(environment(player_list[i])), "players%s#", str);
          if (str)
         write("~"+LADJUST(str,30));
          else {
            str=0;
            sscanf(file_name(environment(player_list[i])), "players%s", str);
            if (str)
           write("~"+LADJUST(str,30));
            else
              write(file_name(environment(player_list[i])));
          }
        }
        else
          write("<location unknown>");
      }
      else {
        if (arg=="l" &&
            (player_list[i]->query_level()<20 &&
             environment(player_list[i]) &&
             environment(player_list[i])->short()))
write("   "+environment(player_list[i])->short());
      }
      write("\n");
      }
    }
  }
  write(HIR+"  ~o~ = vampire      ~:~ = bitten by vampire\n"+NORM);
  write("\n");
  return 1;
}

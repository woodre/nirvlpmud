/*
  list_vampires.h
*/

#include "/players/eurale/defs.h"

/* -------- Friends ---------- */
list_vampires(arg) {
  string str, player_list;
  int i, j;

player_list = EFANGS->sort_list_of_players(users());
write("\n");
if(arg == "l") {
  write(HIR+
    "Name       Level  Gender Status  Ears"+NORM);
  if(TOP_FLOOR->find_officer(TPRN) == MASTER ||
        TOP_FLOOR->find_officer(TPRN) == ASSISTANT)
    write(   "   "+HIR+"Location"+NORM);
}

else {
  write(HIR+"Name       Level  Gender  Status Ears"+NORM);
  if(TOP_FLOOR->find_officer(TPRN) == MASTER ||
        TOP_FLOOR->find_officer(TPRN) == ASSISTANT)
    write(HIR+"  Gexp    Location"+NORM);
}

write("\n");
for (i = 0; i < sizeof(player_list); i++) {
  if(present("vampire fangs", player_list[i]) ||
     present("vampire bite", player_list[i])) {
      if (player_list[i]->query_invis() > 0 &&
          player_list[i]->query_level() > 21)
        j=0; /* don't show wizards on the list if they're invis */
      else
        j = 1;
      if (TOP_FLOOR->find_officer(TPRN) == MASTER ||
          TOP_FLOOR->find_officer(TPRN) == ASSISTANT)
        j = 1;
      /* show this vamp */
      if (j) {
        if (player_list[i]->query_invis() > 0)
          if (player_list[i]->query_level() > TPL)
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
 if(TOP_FLOOR->find_officer(player_list[i]->query_real_name())==LIEUTENANT)
           write(" ~"+RED+"v"+NORM+"~");
        else if(present("vampire bite",player_list[i])) write(" ~:~");
        else
           write(" ~"+RED+"o"+NORM+"~");
        if (present("vampire fangs", player_list[i]) &&
            present("vampire fangs", player_list[i])->
              query_telepathy())
          write("   on ");
        else
          write("   off");
      if ((TOP_FLOOR->find_officer(TPRN) == MASTER ||
           TOP_FLOOR->find_officer(TPRN) == ASSISTANT) &&
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

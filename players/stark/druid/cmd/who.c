#include "/players/stark/defs.h"

druid_who(arg) {
  string str, player_list;
  int i, j;

write("\n"+HIR+
  " Name       Level  Gender Status  Ears    Location"+NORM);

write("\n");
for (i = 0; i < sizeof(player_list); i++) {
  if(present("druid_guild_object", player_list[i])) {
      write(LADJUST(player_list[i]->query_real_name(),12));
      write(LADJUST(player_list[i]->query_level(),6));
      write(LADJUST(player_list[i]->query_gender_string(),6)+"  ");
      write("   "+LADJUST(environment(player_list[i])->short(),35));
      write("\n");
      }
    }
}


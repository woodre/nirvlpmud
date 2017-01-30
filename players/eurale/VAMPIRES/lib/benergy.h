/*
  Check on the Blood Energy of a player
*/

#include "/players/eurale/defs.h"


benergy(str) {
  int blood;
  object obj,target_obj;

  if (this_player()->query_real_name() != "fred" &&
      this_player()->query_real_name() != "rumplemintz" &&
      this_player()->query_real_name() != "khrell" ) {
  write("You cannot use that command.\n");
  return 1; }

if(!str) { write("Who did you want to check?\n"); return 1; }

target_obj = find_player(str);
if(!target_obj) {
  write("Can't find "+capitalize(str)+".\n");
  return 1; }

obj = present("vampire fangs",target_obj);
if(!obj) {
  write("This player is not a vampire.\n");
  return 1; }

blood = obj->query_BLOODPTS();
write(capitalize(str)+" has "+
  blood+HIR+" BLOODPOINTS.\n"+NORM);
write(capitalize(str)+" has vampire skill level of: ");
  if(target_obj->query_guild_exp() >= 670) write("Nosferatu\n");
  if(target_obj->query_guild_exp() == 669) write("Neophyte\n");
  if(target_obj->query_guild_exp() == 668) write("Acolyte\n");
  if(target_obj->query_guild_exp() == 667) write("Novitiate\n");
  if(target_obj->query_guild_exp() == 666) write("Apprentice\n");
return 1;
}

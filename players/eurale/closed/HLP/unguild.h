#include "DEF.h"
 
unguild(str) {
string who;
int num,numer;
object pl;

if(!str) { write("unguild <who> \n"); return 1; }

  sscanf(str,"%s",who);
  if(!find_player(who)) { write("not on... \n"); return 1; }
  pl = find_player(who);
  pl->set_guild_name(0);
  pl->set_guild_rank(0);
  pl->set_guild_exp(0);
  pl->set_guild_file(0);
  num = pl->query_guild_exp();
  numer = pl->query_guild_rank();
  pl->add_guild_exp(-num);
  pl->add_guild_rank(-numer);
write("You have unguilded "+capitalize(who)+".\n");
tell_object(pl,"You feel suddenly empty..... \n");
return 1;
}

#include "../def.h"
cmd_execute(str)
{
  object obj;
  if(TP->query_guild_rank() < 11) return 0;

  obj = find_player(str);
  if(!obj || obj->query_guild_name() != "samurai") return 0;
  if(TP->query_guild_rank() < 11) return 0;
  command("id :forces "+capitalize(str)+" to commit seppuku for "+possessive(obj)+" breaking the laws of Bushido.", TP);
  command("seppuku", obj);
  return 1;
}

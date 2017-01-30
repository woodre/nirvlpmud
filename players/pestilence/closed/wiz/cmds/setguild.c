#include "/bin/wiz/cmd_defs.h"

main(string str)
{
 string who, what;
 object x;
 if(sscanf(str,"%s %s",who,what) < 2)
 {
  write("Usage: 'set_guild <player> guild name\n");
  return 1;
 }
 if(!(x = find_player(who)))
 {
  write("Target is not in play.\n");
  return 1;
 }
 x->set_guild_name(what);
 write("You have set "+CAP(who)+"'s guild name to"+what+".\n");
 return 1;
}

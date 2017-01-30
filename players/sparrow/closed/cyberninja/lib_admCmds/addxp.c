#include "../DEFS.h"


status main(string str)
{
/* Used for guild xp promotion/demotion/setting */
  int amount;
  string who;
  object ob;

  if (!IPTP->guild_manager()) return 0;

  if (!str || !sscanf(str, "%s %d", who, amount) ||
     !find_player(who) || 
     !present(GUILD_ID, find_player(who)))
  {
    write("Usage: addxp <member> <amount>.\n");
    return 1;
  }

  ob = find_player(who);
  IPOB->add_xp(amount);
  ob->add_guild_exp(amount);
  ob->save_me();
  IPOB->save_me();

  if(amount >= 0)
    write("You alter " + capitalize(who) + "'s guild xp by +"
      + amount +".\n");
  else write("You alter " + capitalize(who) + "'s guild xp by "
      + amount +".\n");

  write_file(LOGDIR + "/ADDXP", 
    TPN + " altered " + OPN +
    "'s guild xp by " + amount + ". (" + ctime() + ")\n");
  return 1;
}

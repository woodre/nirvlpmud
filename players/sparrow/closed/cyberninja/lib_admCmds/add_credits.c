#include "../DEFS.h"


status main(string str)
{
/* Used for guild credit promotion/demotion/fixing */
  int amount;
  string who;
  object ob;

  if (!IPTP->guild_manager()) return 0;

  if (!str || !sscanf(str, "%s %d", who, amount) ||
     !find_player(who) || !present(GUILD_ID, find_player(who)))
  {
    write("Usage: add_credits <ninja> <amount>\n");
    return 1;
  }

  ob = find_player(who);
  IPOB->addToBalance(amount);
  IPOB->save_me();

  if(amount >= 0)
    write("You alter " + capitalize(who) + "'s guild credits by +"
      + amount + ".\n");
  else write("You alter " + capitalize(who) + "'s guild credits by "
      + amount + ".\n");

  write_file(LOGDIR + "/BANK",
    TPN+" altered " + OPN + "'s guild credits by " +
    amount + ". (" + ctime() + ")\n");
  return 1;
}

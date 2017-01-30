/* Added a function to filter out invisible wizards */

#include "../DEFS.h"
#include "/obj/security.h"

status filter_invis(object ob) { return ((int)ob->query_invis() < 20); }

status main(string str) {
  object * everyone;
  object member;
  int i, bal;

  if (!call_other(OFFICED,"checkStone",TP,"diamond sapphire pearl ruby emerald onyx"))
    return 0;

  everyone = filter_array(users(), "filter_invis");
  write("Guild Balances\n"+LINE);
  for (i = 0; i < sizeof(everyone); i++)
  {
    if (present(GUILD_ID, everyone[i]))
    {
      member = present(GUILD_ID, everyone[i]);
      bal = (int)member->balance();
      write(pad(capitalize((string)everyone[i]->query_name()), 20));
      write(pad(bal, 8)+" @'s\n");
    }
  }
  write(LINE);
  return 1;
}

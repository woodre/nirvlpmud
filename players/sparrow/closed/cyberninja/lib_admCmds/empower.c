#include "../DEFS.h"
#include DEFS_OFFICES


status main(string str)
{
  string myRole;

  if (!call_other(OFFICED, "checkStone", TP, 
      "diamond sapphire pearl emerald onyx jade opal"))
    return 0;

  if (TP->query_level() >= 21 && !IPTP->guild_manager())
  {
    write("Empower is restricted to players and guild managers only.\n");
    return 1;
  }

  if(!str)
  {
    if (TP->query_level() >= 21)
    {
      myRole = ADMINIUM;
    }
    else
    {
      myRole = (string)call_other(OFFICED, "findRole", this_player());
    }
    call_other(OFFICED, "empowerUsage", myRole);
    return 1;
  }

  if(call_other(OFFICED, "empower", str))
    write("Your delegation of authority succeeded.\n");
  else
    write("Your delegation of authority failed.\n");

  return 1;
}

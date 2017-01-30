#include "../DEFS.h"
#include DEFS_GLEVELS


status main(string str)
{
  string brand;
  object ob;

  if (!str || !find_player(str))
  {
    write("Usage: upgrades <member>.\n");
    return 1;
  }

  ob = find_player(str);

  if (!IPOB)
  {
    write(OPN + " is not a member of the guild.\n");
    return 1;
  }

  if (     IPTP->guild_lev() <= IPOB->guild_lev() &&
      (int)IPTP->guild_lev() < MAX_QUALITY_LEVEL)
  {
    write("You can only view upgrades of lower quality ninjas.\n");
    return 1;
  }

  write("\n~~Available Upgrades for "+OPN+"\n");
  call_other(GLEVELD, "checkBrand", TP, ((int)IPOB->guild_lev())+1, 0);
  write(  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  return 1;
}

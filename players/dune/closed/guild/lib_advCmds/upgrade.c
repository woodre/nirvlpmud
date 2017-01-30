#include "../DEFS.h"
#include DEFS_GLEVELS


status main(string str)
{
  string brand, who;
  object ob, die;

  if (!str || 
      !sscanf(str, "%s %s", who, brand) ||
      !find_player(who))
  {
    write("Usage: upgrade <member> <chipBrand>.\n");
    return 1;
  }

  ob = find_player(who);

  if (!IPOB)
  {
    write(OPN + " is not a member of the guild.\n");
    return 1;
  }

  if (     IPTP->guild_lev() <= IPOB->guild_lev() &&
      (int)IPTP->guild_lev() < MAX_QUALITY_LEVEL)
  {
    write("You can only upgrade ninjas of lower quality than you.\n");
    return 1;
  }

  if (!present(ob, environment(TP)))
  {
    write(OPN+" must be in the same room.\n");
    return 1;
  }

  if (!brand)
  {
    write("\n~~Available Upgrades for "+OPN+":\n");
    call_other(GLEVELD, "checkBrand", TP, 
      ((int)IPOB->guild_lev())+1, 0);
    write("~~~~~~~~~~~~~~~~~~~~~~\n");
    return 1;
  }

  if (!(die = present(brand+"_set", TP)) )
  {
    write("You have not engineered a die set for the "+
      brand+" brand.\n");
    return 1;
  }

  if (call_other(GLEVELD, "advance_member", ob, brand))
  {
    brand = capitalize((string)IPOB->query_brand());
    call_other(CHANNELD, "overchannel", 
      TRN+" has upgraded "+ORN+" to a "+
      brand+" neural processor!\n");
    tell_object(ob, TPN+" has upgraded your processor.\n"+
      "Congratulations!\n");
    destruct(die);
  }
  else write("Could not upgrade "+ORN+"'s neural chip.\n");

  return 1;
}

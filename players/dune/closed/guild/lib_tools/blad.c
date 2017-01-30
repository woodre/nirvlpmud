#include "../DEFS.h"
#include DEFS_ENHANCEMENTS


status main(string str)
{
  /* added dmg enhancement */
  if (!((status)IPTP->item_blades()) && !IPTP->guild_wiz()) return 0;
  if ((status)IPTP->query_blad_on())
  {
    write("You retract your blades.\n");
    say(TPN+" retracts "+TP->POS+" blades.\n");
    IPTP->set_blad_on(0);
    return 1;
  }
  IPTP->set_blad_on(1);

  /* sp drain now occurs only when blades take effect */

  write("Sharp blades emerge from your body.\n");
  say("Sharp blades emerge from "+TPN+"'s body.\n");
  return 1;
}

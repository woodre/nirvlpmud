#include "../DEFS.h"
#include DEFS_ENHANCEMENTS


status main(string str)
{
  /* added dmg enhancement */
  if (!((status)IPTP->item_bionics()) && !IPTP->guild_wiz()) return 0;
  if ((status)IPTP->query_bion_on())
  {
    write("You manually de-activate your bionics.\n");
    say(TPN+" manually de-activates "+TP->POS+" bionics.\n");
    IPTP->set_bion_on(0);
    return 1;
  }

  /* sp drain now occurs only when bionics take effect */

  IPTP->set_bion_on(1);
  write("Bionics engaged.\n");
  say(TPN+" engages "+TP->POS+" bionics.\n");
  return 1;
}

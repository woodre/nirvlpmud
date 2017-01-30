#include "../DEFS.h"
#include DEFS_ENHANCEMENTS


status main(string who)
{
  /* concentrated dmg enhancement */
  status hasFlux;

  hasFlux = (status)IPTP->item_electricflux() ||
            (status)IPTP->item_heatflux()     ||
            (status)IPTP->item_magneticflux();

  if (!hasFlux && !IPTP->guild_wiz())
    return 0;

  write("Fluxes have been merged. The new command is 'flux'.\n"+
        "You may set the type of flux ray with 'flux_set'.\n"+
        "By default, your flux generator will emit a random ray.\n");
  return 1;
}

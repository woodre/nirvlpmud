/*
 *      File:                   shieldcheck.c
 *      Function:               wield_func for dkatana_new.c
 *      Author(s):              Illarion@Nirvana
 *      Created:                10 Nov 2004
 *      Notes:                  Prevents the katana from being wielded if the player is using a shield
 *
 *      Change History:
 */

#include "/players/illarion/dfns.h"

/* 
 * Function name: wield
 * Description: checks wether the player is using a shield
 * Arguments: weapon being wielded (ignored)
 * Returns: int - 1 for allowed to wield, 0 for not
 */

wield() {
  object *inv;
  int s;
  inv=all_inventory(TP);
  if(TP->query_attrib("dex") >= 25)
    return 1;
  s=sizeof(inv);
  while(s--)
    if(inv[s]->query_type()=="shield" && inv[s]->query_worn()) {
      write("You do not have the ability to wield this weapon in one hand.\n");
      return 0;
    }
  return 1;
}

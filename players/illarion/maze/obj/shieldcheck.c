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

wield(object ob) {
  object *inv;
  int s;
  if(!ob->two_handed())
    return 1;
  inv=all_inventory(this_player());
  s=sizeof(inv);
  while(s--)
    if(inv[s]->query_type()=="shield" && inv[s]->query_worn()) {
      write("You may not use a shield with this weapon.\n");
      return 0;
    }
  return 1;
}

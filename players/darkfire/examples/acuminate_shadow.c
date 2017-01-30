#include <ansi.h>
#include "../defs.h"
/******************************************************************************
 * Program: acuminate_shadow.c
 * Path: /players/dragnar/SevenSpires/obj/
 * Type: shadow
 * Created: June 30th, 2015 by Dragnar
 *
 * Purpose: The shadow object cast upon target weapon to make it un-breakable.
 *
 * History:
 *          06/30/2015 - Gnar
 *            Created
 ******************************************************************************/

object weapon;

start_wep_shadow(object ob){
  if( !ob ) { return; }
  if( !environment(ob) ) return;
  if( !environment(ob)->is_player() ) return;
  weapon = ob;
  shadow(weapon, 1);
  return 1; 
}

stop_wep_shadow() {
   object gob, fwep;
   shadow(weapon, 0);
   destruct(this_object());
   return 1; 
}

short() {
  return weapon->short()+BOLD+" [Acuminated]"+NORM; 
}

is_acuminated() { return 1; }

query_wear() {
  return 1;
}

weapon_breaks() {
  return 1;
}

/*                                                                    *
 *    File:             /players/angel/area/atlantis/obj/rgun.c       *
 *    Function:         obj/weapon                                    *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2006 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           11/15/06                                      *
 *    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */

#include "/sys/lib.h"

#include <ansi.h>

inherit "obj/weapon.c";

reset(arg) {
  ::reset(arg);
  if (arg) return;
  set_name("ronon's gun");
  set_alias("gun");
  set_type("lazer");
  set_short(HIC+"Ronon's Gun"+NORM);
  set_long("Little is known about this light weight weapon. Only that\n\
Ronon Dex's is the only one with this type of weapon and\n\
rather than bullets, the device emits great red bursts of\n\
energy.\n");
  set_class(19);
  set_weight(1);
  set_value(2000);
  set_hit_func(this_object());
  set_params("other|laser",1,"laser_hit");
}

/* Function name:
 * Description:  
 *            
 * Arguments: 
 * Returns: 
 */
/* special attack */
laser_hit(attacker){
  if (random(20)>6) {
    say(""+HIC+"Ronon Dex's gun"+NORM+" Knocks You Down with a "+HIR+"Red Bursts"+NORM+" of "+HIW+"Energy!"+NORM+"\n");
    write(""+HIC+"Ronon Dex's gun"+NORM+" Knocks your Foe Down with a "+HIR+"Red Bursts"+NORM+" of "+HIW+"Energy!"+NORM+"\n");
    return random(5); /* Changed by Fred used to return 2010 */
  }
}

/* Function name: weapon break
 * Description:
 *       stops weapon from breaking  
 * Arguments:
 * Returns:
 */
weapon_breaks()
{
  return 1;
}

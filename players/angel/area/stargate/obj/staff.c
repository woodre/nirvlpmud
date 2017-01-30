/*                                                                    *
 *    File:             /players/angel/area/stargate/obj/staff.c      *
 *    Function:         obj/ weapon                                   *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2006 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           1/15/07                                       *
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
  set_name("staff weapon");
  set_alias("staff");
  set_type("staff");
  set_short(HIC+"STAFF WEAPON"+NORM);
  set_long("A weapon of Goa'uld design. Several feet in length, its head divides\n\
  into four parts when activated, releasing powerful bolts of plasma\n\
  energy. The weapon is powered by a small, green container of liquid\n\
  naquadah.\n");
  set_class(19);
  set_weight(2);
  set_value(2000);
  set_hit_func(this_object());
  set_params("other|laser",1,"laser_hit");
}

/* Function name: laser_hit ()
 * Description:   special attack
 *            
 * Arguments: 
 * Returns: 
 */
laser_hit(attacker){
  if (random(15)>6) {
    say(""+HIB+"The S T A F F gun B L A S T your F O E ' S flesh!"+NORM+"\n");
    write(""+HIB+"The S T A F F gun B L A S T your F O E ' S flesh!"+NORM+"\n");
    return 5;
  }
}

/* Function name: weapon_breaks ()
 * Description:  weapon can not break
 *            
 * Arguments: 
 * Returns: 
 */
weapon_breaks()
{
  return 1;
}
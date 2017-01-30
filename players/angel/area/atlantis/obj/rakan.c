/*                                                                    *
 *    File:             /players/angel/area/atlantis/obj/rakan.c      *
 *    Function:         obj/ weapon                                   *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2007 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           12/15/07                                      *
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
  set_name("rakan bo");
  set_alias("staff");
  set_type("staff");
  set_short(YEL+"Rakan Bo Staff"+NORM);
  set_long("This staff is 3 feet in length and is concealed as a cane. It\n\
  has a sword blade inside it that can retract out during battle.\n\
  Using proper techniques, a Rakan Bo with out the blade can easily \n\
  break bones and damage internal organs.\n");
  set_class(19);
  set_weight(1);
  set_value(10000);
  set_hit_func(this_object());
  set_params("other|physical",1,"flesh_hit");
}

/* Function name: flesh_hit ()
 * Description:   special attack
 *            
 * Arguments: 
 * Returns: 
 */
flesh_hit(attacker){
  if (random(15)>6) {
    say(""+HIB+"The BO  S T A F F  SLICES your F O E ' S flesh!"+NORM+"\n");
    write(""+HIB+"The BO  S T A F F SLICES your F O E ' S flesh!"+NORM+"\n");
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

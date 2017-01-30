/*                                                                    *
 *    File:             /players/angel/area/atlantis/obj/escrima.c    *
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
  set_name("dragon escrima");
  set_alias("staff");
  set_alt_name("escrima");
  set_type("staff");
  set_short(YEL+"D"+HIY+"r"+HIR+"a"+NORM+RED+"g"+YEL+"o"+HIY+"n"+HIR+" E"+NORM+RED+"s"+YEL+"c"+NORM+HIY+"r"+HIR+"i"+NORM+RED+"m"+YEL+"a"+NORM);
  set_long("This staff is 2 feet in length and 1 inch thick.\n\
It is lightweight and very durable. It is made from\n\
white wax wood with striking burn pattern give it an\n\
exotic, unique look \n");
  set_class(17);
  set_weight(1);
  set_value(1000);
  set_hit_func(this_object());
  set_params("other|physical",1,"dragon_hit");
}

/* Function name: dragon_hit ()
 * Description:   special attack
 *            
 * Arguments: 
 * Returns: 
 */
dragon_hit(attacker){
  if (random(15)>6) {
    say(""+YEL+BLINK+"D"+HIY+"R"+HIR+"A"+NORM+RED+BLINK+"G"+YEL+"O"+HIY+"N"+HIR+" E"+NORM+RED+BLINK+"S"+YEL+"C"+NORM+HIY+BLINK+"R"+HIR+"I"+NORM+RED+BLINK+"M"+YEL+"A"+NORM+" "+HIR+"SLICES your F O E ' S flesh!"+NORM+"\n");
    write(""+YEL+BLINK+"D"+HIY+"R"+HIR+"A"+NORM+RED+BLINK+"G"+YEL+"O"+HIY+"N"+HIR+" E"+NORM+RED+BLINK+"S"+YEL+"C"+NORM+HIY+BLINK+"R"+HIR+"I"+NORM+RED+BLINK+"M"+YEL+"A"+NORM+" "+HIR+"SLICES your F O E ' S flesh!"+NORM+"\n");
    return 5;
  }
}

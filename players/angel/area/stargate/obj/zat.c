/*                                                                    *
 *    File:             /players/angel/area/stargate/obj/zat.c        *
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

string dis_type;

reset(arg) {
  ::reset(arg);
  if (arg) return;
  dis_type="heal";
  set_name("Zat'ni'katel");
  set_alias("zat");
  set_type("lazer");
  set_short(HIC+"Zat'ni'katel"+NORM);
  set_long("A tau'ri modified handheld Goa'uld weapon, formed in the shape of a\n\
coiled serpent. The zat'ni'katel was nicknamed 'zat gun' by Colonel\n\
O'Neill. The zat uses a different form of energy, less powerful than\n\
that of an authentic Goa'uld Zat'ni'katel. Once you have killed a mob\n\
one shots can 'disintegrate' the 'corpse'.\n");
  set_class(19);
  set_weight(2);
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
    say(""+HIB+"The ZAT gun burns off your foe's flesh with a bright blue LAZER!"+NORM+"\n");
    write(""+HIB+"The ZAT gun burns off your foe's flesh with a bright blue LAZER!"+NORM+"\n");
    return 5;
  }
}

/* Function name:
 * Description:  
 *            
 * Arguments: 
 * Returns: 
 */
/* stops weapon from breaking */
weapon_breaks()
{
  return 1;
}

init()
{
  /* action to destroy corpse and follows the theme for the weapon*/
  add_action("disintegrate_corpse", "disintegrate");
  add_action("disintegrate_corpse", "dis");
}


/* Function name:  disintegrate_corpse()
 * Description:    gives heal points
 *            
 * Arguments: 
 * Returns: 
 */
disintegrate_corpse()  {
  string dis_func;
object corpse;
int heal;
heal = 0;
    corpse = present("corpse",environment(this_player()));
      if(!corpse)  {
    corpse = present("corpse",this_player());
    }
      if(!corpse)  {
        write("There is no corpse here to disintegrate.\n");
    return 1;
    }
  /* function that gives players some heal value out of the corpse */
  heal=corpse->heal_value();
    if(dis_type=="SP") { heal *= 2; dis_func = "add_sp"; }
      else if(dis_type=="HP") { heal *= 2; dis_func = "add_hp"; }
      else dis_func = "heal_self";
  call_other(this_player(),dis_func, heal);
    write("You disintegrate the corpse and feel stronger.\n");
    say(this_player()->query_name()+" pulls the trigger on the zat gun and disintegrate the corpse.\n"+
    this_player()->query_name()+" looks stronger.\n");
  this_player()->print_monitor();
    destruct(corpse);
    return 1;
}
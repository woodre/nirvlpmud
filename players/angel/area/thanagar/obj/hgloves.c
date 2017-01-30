/*                                                                    *
 *    File:             /players/angel/area/thanagar/room/hgloves.c   *
 *    Function:         obj                                           *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2008 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           08/08/08                                      *
 *    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */

#include "/sys/lib.h"

#include <ansi.h>

#define USER environment(this_object())

#define ATT USER->query_attack()

inherit "/obj/armor";

id(str) { return str == "hgloves" || str == "gloves"; }

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("gloves");
   set_short(HIY+"Hawkman's Golden Gloves"+NORM);
   set_long("\This is "+HIY+"Hawkman's Golden Gloves"+NORM+". They are made of "+CYN+"Nth Metal"+NORM+" which\n\
defy gravity. "+CYN+"Nth Metal"+NORM+" has many other unknown properties.\n");
   set_ac(2);
   set_type("gloves");
   set_weight(2);
   set_value(10000);
}

/* Function name:
 * Description:
 *
 * Arguments:
 * Returns:
 */
do_special(owner){
  int msg;
  if(!worn) return;
  if (!owner || !owner->query_attack())
    return;

    switch(random(6)){
      case 0: msg = ""+HIW+BLINK+"Enhanced Strength"+NORM+" "+HIY+"level is increased by the"+NORM+" "+CYN+"Nth metal,"+NORM+" "+HIW+BLINK+"Ripping Apart"+NORM+"";
      break;
      case 1: msg = ""+HIW+BLINK+"Enhanced Durability"+NORM+" "+HIY+"withstands"+NORM+" "+HIW+BLINK+"Blows"+NORM+" "+HIY+"from"+NORM+"";
      break;
      case 2: msg = ""+HIW+BLINK+"Enhanced Vision"+NORM+" "+HIY+"allows objects to be seen at speeds faster than can be\n"+
                    "perceived by the normal eye and BLINK+DODGES powerful "+HIW+BLINK+"ATTACKS"+NORM+" "+HIY+"from"+NORM+"";
      break;
      case 3: msg = ""+HIW+BLINK+"Power"+NORM+" "+HIY+"from the"+NORM+" "+CYN+"Nth Metal"+NORM+" "+HIY+"grants Flight to"+NORM+" "+HIW+BLINK+"DODGE ATTACKS"+NORM+" "+HIY+"from"+NORM+"";
      break;
      case 4: msg = ""+HIW+BLINK+"Energy Disruption"+NORM+" "+HIY+"causes a disturbance in the very force drawn\n"+
                    "from the fabric of "+BLINK+"time and space"+NORM+" "+HIW+"DODGING"+NORM+"";
      break;
      case 5: msg = ""+HIW+BLINK+"Enhanced Healing Factor"+NORM+" "+HIY+"heals"+NORM+" "+HIW+BLINK+"ATTACK"+NORM+" "+HIY+"wounds from"+NORM+"";
      break;
}
  if(random(6))
  {
	tell_object(owner,
	  owner->query_name()+"'s "+msg+" "+owner->query_attack()->short()+"!\n");
    tell_room(environment(owner),
      owner->query_name()+"'s "+msg+" "+owner->query_attack()->short()+"!\n", ({ owner }));
    owner->add_hit_point(2+random(6));
    return 10;
  }
  return;
}
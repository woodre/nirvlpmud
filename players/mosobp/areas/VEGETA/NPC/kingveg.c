/*                                       
 *  File:   /players/mosobp/areas/BATTLE/NPC/krillen.c
 *  Function:  mob                      
 *  Author(s):  Mosobp@Nirvana           
 *  Copyright: copyright (c) 2008 Mosobp 
 *             all rights reserved          
 *                                       
 *                                       
 *  Source:  6/17/08                    
 *  Notes:                               
 *                                       
 *                                       
 *  Change History:                      
 */

#include "/sys/lib.h"

#include <ansi.h>

inherit "/obj/monster";

reset(arg)
{
  object gold;
  ::reset(arg);
  if(arg) return;
  set_name("king vegeta");
  set_alias("vegeta");
  set_alias("king");
  set_short(HIK+"King Vegeta"+NORM);
  set_race("saiyan");
  set_long(
  "Krillen is a defender of the earth, and part of the Z Force. He has helped\n"+
  "Goku defend the earth against countless threats, without regard to\n"+
  "his own life.\n");
  set_level(25);
  set_hp(1400+random(550));
  set_al(1000);
  gold=clone_object("obj/money");
  gold->set_money(random(2000)+10000);
  set_wc(47);
  set_ac(18);
  set_heal(45,8);
  add_spell("destructodisc",
    "A round circular "+HIY+"DISC"+NORM+" screams toward you hitting your chest!\n",
    "#MN# forms a circular "+HIY+"DISC "+NORM+"above his hand and throws it!.\n",
    15,"100-120","other|energy");
  add_spell("kamaehamaeha",
    "A Bright "+HIC+"BEAM "+NORM+"of light fly's toward you hitting your face!\n",
    "#MN# screams: "+HIC+"KA MAE HA MAE HAAA!! "+NORM+"and a beam screams forward.\n",
    20,"110-150","other|energy");
}
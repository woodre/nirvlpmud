/*                                       
 *  File:   /players/mosobp/areas/TOWER/NPC/salt.c
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
  set_name("salt");
  set_short(HIR+"Salt"+NORM);
  set_race("mako");
  set_long(
  
  "One of the weaker of Garlic jr.'s henchman, he follows the others\n"+
  "orders. He only attacks when they do.\n");
  
  set_level(20);
  set_hp(500+random(200));
  set_al(-1000);
  gold=clone_object("/obj/money");
  gold->set_money(random(500)+1400);
  move_object(gold,this_object());
  move_object(clone_object("/players/mosobp/areas/TOWER/OBJ/gloves.c"), this_object());
  init_command("wear gloves");
  if(!random(6)) 
    move_object(clone_object("/players/mosobp/areas/TOWER/OBJ/wbottle.c"), this_object());
  set_wc(30+random(15));
  set_ac(15+random (5));
  set_aggressive(1);
  
}
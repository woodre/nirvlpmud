/*                                       
 *  File:   /players/mosobp/areas/TOWER/NPC/nappa.c
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
  set_name("nappa");
  set_short(BLU+"Nappa"+NORM);
  set_race("saiyan");
  set_long(
  
  "Nappa is Vegeta's faithful follower. He begins the attack on the\n"+
  "Earths defenders when the saiyans attacked the earth.\n");
 
  set_level(20);
  set_hp(600+random(150));
  set_al(-1000);
  gold=clone_object("/obj/money");
  gold->set_money(random(2150));
  move_object(gold,this_object());
  move_object(clone_object("/players/mosobp/areas/TOWER/OBJ/sarmor.c"), this_object());
  init_command("wear armor");
  move_object(clone_object("/players/mosobp/areas/TOWER/OBJ/sboots.c"), this_object());
  init_command("wear boots");
  if(!random(6)) 
    move_object(clone_object("/players/mosobp/areas/TOWER/OBJ/wbottle.c"), this_object());
  set_wc(25+random(15));
  set_ac(15);
  add_spell("kiblast",
  "A giant blast of "+HIY+" ENE RGY "+NORM+" hits your legs!\n",
  "#MN# focuses his "+HIY+" ENE RGY "+NORM+" and shoots it from his fingers!\n",
  30,60, "other|energy");
  
}

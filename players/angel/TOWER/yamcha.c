/*                                       
 *  File:   /players/mosobp/areas/TOWER/NPC/yamcha.c
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
  set_name("yamcha");
  set_short(HIY+"Yamcha"+NORM);
  set_race("human");
  set_long(
  "Yamcha is one of the weakest defenders of earth, but he continues\n"+
  "to try to help the others when a threat arises.\n");
  set_level(20);
  set_hp(600);
  set_al(-1000);
  gold=clone_object("/obj/money");
  gold->set_money(2000+random (2000));
  move_object(gold,this_object());
  set_wc(30);
  set_ac(15);
  set_heal(30,10);
  add_spell("kipunch",
  "#MN# "+HIY+" P U N C H E S "+NORM+" you in the shoulder!!\n",
  "#MN# "+HIY+" P U N C H E S "+NORM+" #TN# in the shoulder.\n",
  50,40, "other|physical");
  
}
/*                                       
/players/mosobp/areas/TOWER/NPC/tien.c
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
  set_name("tien");
  set_short(HIY+"Tien"+NORM);
  set_race("human");
  set_long(
  "Tien is one of Earth's defenders, he helps Goku and the others\n"+
  "defend the earth from invaders. His power level is no match for\n"+
  "even Piccolo but that doesnt stop him from trying.\n");
  
  set_level(20);
  set_hp(600+random(300));
  set_al(750);
  gold=clone_object("/obj/money");
  gold->set_money(random(1000)+3900);
  move_object(gold,this_object());
  if(!random(6)) 
    move_object(clone_object("/players/mosobp/areas/TOWER/OBJ/wbottle.c"), this_object());
  set_wc(30+random(15));
  set_ac(15+random (5));
  set_heal(125,10);
  set_multi_cast(1);
  add_spell("kiblast",
  "A "+YEL+" BEAM "+NORM+" of energy hits you in the "+HIB+" S H O U L D E R "+NORM+" !!!\n",
  "#MN# shoots a "+YEL+" B E A M "+NORM+" of energy from his hand.\n",
  40,"25-35", "other|laser");
  
  add_spell("punch",
  "#MN#'s "+HIR+" F I S T "+NORM+" hits you right in the stomach.\n",
  "#MN# PUNCHES #TN# in the stomach!\n",
  45,"10-30", "other|physical");

}

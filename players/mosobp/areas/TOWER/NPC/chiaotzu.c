/*                                       
 *  File:   /players/mosobp/areas/TOWER/NPC/chiaotzu.c
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
  set_name("chiaotzu");
  set_short(HIY+"Chiaotzu"+NORM);
  set_race("human");
  set_long(
  "Chiaotzu is a small guy of about 3 ft in height, he trains with\n"+
  "Tien deep in the mountains. His low power level never seems to\n"+
  "increase at the same pace as the rest of the Z fighters.\n");
  set_level(17);
  set_hp(500);
  set_al(1000);
  gold=clone_object("/obj/money");
  gold->set_money(1400);
  move_object(gold,this_object());
  if(!random(6)) 
    move_object(clone_object("/players/mosobp/areas/TOWER/OBJ/wbottle.c"), this_object());
  set_wc(24);
  set_ac(14);

}
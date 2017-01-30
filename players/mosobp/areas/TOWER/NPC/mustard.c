/*                                       
 *  File:   /players/mosobp/areas/TOWER/NPC/mustard.c
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
  set_name("mustard");
  set_short(HIY+"Mustard"+NORM);
  set_race("mako");
  set_long(
  "Mustard is one of Garlic jr.'s henchmen he's not really a match\n"+
  "for any of the z fighters but together with the other 2 henchmen\n"+
  "they can make it appear to be a fight.\n");
  
  set_level(20);
  set_hp(500+random(150));
  set_al(-1000);
  gold=clone_object("/obj/money");
  gold->set_money(random(1000)+2400);
  move_object(gold,this_object());
  move_object(clone_object("/players/mosobp/areas/TOWER/OBJ/gloves.c"), this_object());
  init_command("wear gloves");  
  if(!random(6)) 
    move_object(clone_object("/players/mosobp/areas/TOWER/OBJ/wbottle.c"), this_object());
  set_wc(30);
  set_ac(17);
  set_aggressive(1);
  set_heal(45,10);
  add_spell("punch",
  "#MN# swings around to your side and "+RED+" P U N C H E S "+NORM+" your side!\n",
  "#MN# swings around to the side punching #TN# in the side!\n",
  30,50, "other|physical");

}
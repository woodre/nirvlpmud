/*                                       
 *  File:   /players/mosobp/areas/VEGETA/NPC/fasha.c
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
  set_name("fasha");
  set_short(YEL+"Fasha"+NORM);
  set_race("human");
  set_long(
  "Fasha is a member of the illustrious saiyan army, and the only \n"+
  "female member of Bardock's group. She wears the battle armor \n"+
  "with shoulder pads. She is also wearing a scouter and a cloth\n"+
  "wrapped around her waist.");
  set_level(25);
  set_hp(1400+random(550));
  set_al(1000);
  gold=clone_object("obj/money");
  gold->set_money(random(2000)+10000);
  move_object(gold, this_object());
  move_object(clone_object("/players/mosobp/areas/VEGETA/OBJ/scouter.c"), this_object());
  init_command("wear scouter");
  set_wc(47);
  set_ac(18);
  set_heal(35,7);
  add_spell("",
    "A round circular "+HIY+"DISC"+NORM+" screams toward you hitting your chest!\n",
    "#MN# forms a circular "+HIY+"DISC "+NORM+"above his hand and throws it!.\n",
    15,"100-120","other|energy");
  add_spell("kamaehamaeha",
    "A Bright "+HIC+"BEAM "+NORM+"of light fly's toward you hitting your face!\n",
    "#MN# screams: "+HIC+"KA MAE HA MAE HAAA!! "+NORM+"and a beam screams forward.\n",
    20,"110-150","other|energy");
}
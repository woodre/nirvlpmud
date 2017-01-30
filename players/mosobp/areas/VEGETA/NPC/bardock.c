/*                                       
 *  File:   /players/mosobp/areas/VEGETA/NPC/bardock.c
 *  Function:  mob                      
 *  Author(s):  Mosobp@Nirvana           
 *  Copyright: copyright (c) 2008 Mosobp 
 *             all rights reserved          
 *                                       
 *                                       
 *  Source:  8/30/14
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
  set_name("bardock");
  set_short(HIB+"Bardock"+NORM);
  set_race("saiyan");
  set_long(
  "Bardock is a member of the Saiyan guards, and was one of the first to\n"+
  "stand up against Frieza's tyranny. He is also known as the father of Goku,\n"+
  "and was known as a low class soldier although he created the fake moon.\n");
  set_level(25);
  set_hp(1400+random(550));
  set_al(1000);
  gold=clone_object("obj/money");
  gold->set_money(random(2000)+10000);
  move_object(gold, this_object());
  set_wc(47);
  set_ac(18);
  set_heal(35,7);
  add_spell("kiblast",
    "#MN# shoots a series of "+HIY+"K"+HIR+"I"+HIB+" B"+HIG+"L"+HIK+"A"+HIC+"S"+HIM+"T"+NORM+"!!\n",
    "#MN# forms a circular "+HIY+"DISC "+NORM+"above his hand and throws it!.\n",
    15,"100-120","other|energy");
  add_spell("kamaehamaeha",
    "A Bright "+HIC+"BEAM "+NORM+"of light fly's toward you hitting your face!\n",
    "#MN# screams: "+HIC+"KA MAE HA MAE HAAA!! "+NORM+"and a beam screams forward.\n",
    20,"110-150","other|energy");
}
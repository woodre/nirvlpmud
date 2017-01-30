/*                                       
 *  File:   /players/mosobp/areas/TOWER/NPC/garlicjr.c
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
int heal, x;
object *stuff;

reset(arg)
{
  object gold;
  ::reset(arg);
  if(arg) return;
  set_name("garlic jr.");
  set_alias("garlic");
  set_short(MAG+"Garlic Jr."+NORM);
  set_race("mako");
  set_long(
  "After escaping from the dead zone, He vowed to\n"+
  "get revenge on Gohan and Goku for imprisoning him there.\n"+
  "He devises a way to overpower them by using the Mako Star.\n");
  heal = 2;
  set_hp_bonus(1500);
  set_level(25);
  set_hp(1000+random(400));
  set_al(-1000);
  gold=clone_object("/obj/money");
  gold->set_money(random(3400)+7000);
  move_object(gold,this_object());
  move_object(clone_object("/players/mosobp/areas/TOWER/OBJ/daura.c"), this_object());
  init_command("wear aura");
  if(!random(6)) 
    move_object(clone_object("/players/mosobp/areas/TOWER/OBJ/wbottle.c"), this_object());
  set_wc(55);
  set_ac(23);
  set_heal(45,5);
  set_multi_cast(1);
  add_spell("kipunch",
  "#MN# focuses energy into his fist and "+HIB+"PUNCHES"+NORM+" you in the stomach!\n",
  "#MN# rushes forward and "+HIB+"PUNCHES"+NORM+" #TN# in the stomach!\n",
  45,90,"other|physical");
  
  add_spell("kiblast",
  "#MN# hurls a "+MAG+"B E A M"+NORM+" of energy at you!\n",
  "#MN$ hurls a "+MAG+"B E A M"+NORM+" of energy.\n",
  20,"100-150","other|energy");

 add_spell("heal_check", 0, 0, 100, 0, 0, 0, "heal_check");
}

void heal_check(object target, object room, int damage) {
	if(!environment()) return ;
	
	if(heal && (this_object()->query_hp() < 400))
	{
		this_object()->heal_self(750);
    tell_room( environment(this_object()), 
      MAG+"Garlic Jr."+NORM+" screams as he sends out an "+HIY+"Energy Burst"+NORM+"!\n");
		add_spell("energy_burst", 0, 0, 100, "125-130", "other|energy", 3, "remove_energy_burst" );
		heal--;
	}
}

void remove_energy_burst(object target, object room, int damage) {
  remove_spell("energy_burst");
}
  


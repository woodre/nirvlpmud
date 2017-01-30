/*                                       
 *  File:   /players/mosobp/areas/TOWER/NPC/piccolo.c
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
 *  Updated to match piccolo_dragnar.c to account for changes.  
 */

inherit "/obj/monster";
#include "/sys/lib.h"

#include <ansi.h>

int heal, x;
object *stuff;

reset(arg)
{
  object gold;
  ::reset(arg);
  if(arg) return;
  set_name("piccolo");
  set_short(GRN+"Piccolo"+NORM);
  set_race("namekian");
  set_long(
  "Here stands a warrior of the Planet Namek who arrived on\n"+
  "Earth at a very young age.  Early on he had aspirations of\n"+
  "world domination. After training Gohan something in him\n"+
  "changes and he begins to help the z fighters defend the planet\n"+
  "from any threat.\n");
  heal = 3;
  set_level(29);
  set_hp_bonus(2250);
  set_hp(1500+random(1000));
  set_al(1000);
  gold=clone_object("/obj/money");
  gold->set_money(random(24000)+14400);
  move_object(gold,this_object());
  set_wc(55);
  /** Added by Gnar for energy_burst spell (gets removed) **/
  set_wc_bonus(15); 
  set_ac(25+random(10));
  set_heal(40,4);
  move_object(clone_object("/players/mosobp/areas/BATTLE/OBJ/eaura.c"), this_object());
  init_command("wear aura");
  move_object(clone_object("/players/mosobp/areas/TOWER/OBJ/pants.c"), this_object());
  init_command("wear pants");
  if(!random(6)) 
    move_object(clone_object("/players/mosobp/areas/TOWER/OBJ/wbottle.c"), this_object());
  set_multi_cast(1);
  add_spell("masenko",
"A thick "+HIY+"YELLOW BEAM"+NORM+" hits you squarely in the chest!\n",
  "#MN# places his hands above his head and screams: "+HIY+"MASENKO "+NORM+" !\n",
  15,"125-150","other|energy");
  
  add_spell("beam cannon",
  "A spiraling ball of "+HIR+"FIRE"+NORM+" strikes your body!\n",
  "#MN# screams: "+HIR+"Special BEAM Cannon"+NORM+" !!\n",
  15,"75-90","other|fire");
  
  add_spell("heal_check", 0, 0, 100, 0, 0, 0, "heal_check");
}

void heal_check(object target, object room, int damage) {
	if(!environment()) return ;
	
	if(heal && (this_object()->query_hp() < 400))
	{
		this_object()->heal_self(750);
    tell_room( environment(this_object()), 
      GRN+"Piccolo"+NORM+" screams as he sends out an "+HIY+"Energy Burst"+NORM+"!\n");
		add_spell("energy_burst", 0, 0, 100, "120-130", "other|energy", 3, "remove_energy_burst" );
		heal--;
	}
}

void remove_energy_burst(object target, object room, int damage) {
  remove_spell("energy_burst");
}
  


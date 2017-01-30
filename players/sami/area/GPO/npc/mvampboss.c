inherit "/obj/monster.c";
#include <ansi.h>
#define tpn this_player()->query_name()
#include "/sys/lib.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;
	
  set_name("dameon");
  set_alias("vampire");
  set_race("demon");
  set_short("Dameon "+HIG+"("+HIK+"Mid Boss"+HIG+")"+NORM+"");
  set_long(
    " A sinister looking vampire stands here clad in a dark cloak and a\n"+
    " Golden ankh worn around his neck. A Golden ring shimmers from his\n"+
	" right hand. Dameon is one of the 4 servants of Vlad the impaler.\n");
	
move_object(clone_object("/players/sami/closed/cube.c"),this_object());
move_object(clone_object("/players/sami/area/GPO/obj/pants.c"),this_object());
init_command("wear pants");
	move_object(clone_object("/players/sami/area/GPO/obj/grace.c"),this_object());
init_command("wield grace");

  set_level(23);
  set_hp(1000+random(600));
  add_money(3123);
  set_ac_bonus(25);
  set_armor_params("other|evil",0,25,0);
  set_armor_params("other|dark",0,25,0);
  set_armor_params("magical",0,-25,0);
  set_armor_params("other|good",0,-25,0);
  set_al(-800);
  set_heal(15,10);
  set_ac(45+random(8));
  set_wc(27+random(12));
  set_aggressive(0);
  set_multi_cast(1);
 
 add_spell("claw_swipe",
  ""+HIK+"#MN#'s"+NORM+" claws flays you with "+HIY+"burt"+HIB+" of speed"+NORM+".\n",
  ""+HIK+"#MN#"+NORM+" tears into #TN#'s "+HIY+"flesh"+NORM+" with his jagged claws.\n",
  30,({10,10}),({"other|evil","other|earth"}),1);
  add_spell("roundhouse_kick", 
   ""+HIK+"#MN# "+NORM+" delivers a deadly"+HIB+" roundhouse"+NORM+" to your "+HIR+" abdomen"+NORM+".\n",
  ""+HIK+"#MN# "+NORM+" delivers a deadly"+HIB+" roundhouse"+NORM+" to #TN#'s "+HIR+" abdomen"+NORM+".\n",
  25,({15,10}),({"other|evil","other|earth"}),1);
  
  add_spell("ring_pulse", 
   ""+HIK+"#MN#'s"+NORM+" ring radiates"+HIB+" POWER "+NORM+" that pierces your "+HIR+" mind"+NORM+".\n",
  ""+HIK+"#MN#'s"+NORM+" ring radiates"+HIB+" POWER "+NORM+" that pierces #TN#'s "+HIR+" mind"+NORM+".\n",
  10,({20,25}),({"other|evil","other|physical"}),1);
  
    
  add_spell("flames_of_hell",
  ""+HIK+"#MN#"+NORM+" summons"+HIR+" Hellfire"+NORM+" that "+RED+"scourches"+NORM+" your skin!\n",
  ""+HIK+"#MN#"+NORM+" summoned"+HIR+" Hellfire"+NORM+" that "+RED+"scourches"+NORM+" #TN#'s skin!\n",
   10,({20,20}),({"other|evil","other|fire"}),1);
   
   } 

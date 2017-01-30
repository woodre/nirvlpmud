inherit "/obj/monster.c";
#include <ansi.h>
#define tpn this_player()->query_name()
#include "/sys/lib.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;
	
  set_name("mikal");
  set_alias("vampire");
  set_race("demon");
  set_short("Mikal "+HIG+"("+HIK+"Mid Boss"+HIG+")"+NORM+"");
  set_long(
    " A sinister looking vampire stands here clad in a dark cloak and a\n"+
    " Golden ankh worn around his neck. A earring shimmers from his right\n"+
	" hand. Mikal is one of the 3 servants of Vlad the impaler.\n");
	move_object(clone_object("/players/sami/area/GPO/obj/dring.c"),this_object());
init_command("wear ring");
	move_object(clone_object("/players/sami/area/GPO/obj/vmace.c"),this_object());
init_command("wield mace");
move_object(clone_object("/players/sami/closed/cube.c"),this_object());
  set_level(22);
  add_money(4000+random(4000));
  set_hp(500+random(200));
  set_ac_bonus(25);
  set_armor_params("other|evil",0,25,0);
  set_armor_params("other|dark",0,25,0);
  set_armor_params("magical",0,25,0);
  set_armor_params("other|good",0,-25,0);
  set_al(-800);
  set_heal(20,5);
  set_ac(34+random(8));
  set_wc(20+random(12));
  set_aggressive(0);
 set_multi_cast(1);
 
 add_spell("claw_swipe",
  ""+HIK+"#MN#'s"+NORM+" claws flays you with "+HIY+"burt"+HIB+" of speed"+NORM+".\n",
  ""+HIK+"#MN#"+NORM+" tears into #TN#'s "+HIY+"flesh"+NORM+" with his jagged claws.\n",
  30,({25,15}),({"other|evil","other|earth"}),1);
  add_spell("roundhouse_kick", 
   ""+HIK+"#MN# "+NORM+" delivers a deadly"+HIB+" roundhouse"+NORM+" to your "+HIR+" abdomen"+NORM+".\n",
  ""+HIK+"#MN# "+NORM+" delivers a deadly"+HIB+" roundhouse"+NORM+" to #TN#'s "+HIR+" abdomen"+NORM+".\n",
  25,({25,25}),({"other|evil","other|earth"}),1);
  
  add_spell("ring_pulse", 
   ""+HIK+"#MN#'s"+NORM+" ring radiates"+HIB+" POWER "+NORM+" that pierces your "+HIR+" mind"+NORM+".\n",
  ""+HIK+"#MN#'s"+NORM+" ring radiates"+HIB+" POWER "+NORM+" that pierces #TN#'s "+HIR+" mind"+NORM+".\n",
  10,({45,25}),({"other|evil","other|physical"}),1);
  

  
   } 
   

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
    " Golden ankh worn around his neck. A Golden ring shimmers from his\n"+
        " right hand. Mikal is one of the 4 servants of Vlad the impaler.\n");
        move_object(clone_object("/players/sami/area/GPO/obj/dring.c"),this_object());
init_command("wear ring");
move_object(clone_object("/players/sami/area/GPO/obj/lvampsword.c"),this_object());
init_command("wield sword");
move_object(clone_object("/players/sami/closed/cube.c"),this_object());
move_object(clone_object("/players/sami/closed/cube.c"),this_object());
  set_level(20);
  set_hp(500+random(200));
  set_hp_bonus(650);
  set_armor_params("other|evil",0,25,0);
  set_armor_params("other|dark",0,25,0);
  set_armor_params("other|magical",0,25,0);
  set_al(-800);
  set_heal(10,10);
  set_ac(30+random(8));
  set_wc(20+random(12));
  set_aggressive(0);
 set_multi_cast(5);
 
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

init() {
	::init();
}

heart_beat() {
	::heart_beat();
}
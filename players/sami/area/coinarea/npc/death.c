inherit "/obj/monster.c";
#include "/sys/lib.h"
#include <ansi.h>
#define tpn this_player()->query_name()
#define ATT USER->query_attack()

reset(arg) {
  ::reset(arg);
  if(arg) return;
	
  set_name("grim");
  set_alias("reaper");
  set_race("hologram");
  set_short("The "+HIK+"Grim"+NORM+" reaper");
  set_long(
    " A shadowy figure, cloaked in a seamless tunic that seems to drape to the floor.\n"+
    " A bony hand grasps a magnificent scythe; forged from some unknown alloy. Red\n"+
	" eyes glare from underneath the hood. He appears to be Extremely "+HIR+"Dangerous"+NORM+".\n");
  set_level(24);
  set_hp(2000+random(500));
  set_heal(10,10);
  set_al(-800);
  set_ac(34+random(6));
  set_wc(45);
  set_aggressive(0);
  set_armor_params("other|evil",0,50,0);
  set_armor_params("other|dark",0,50,0);
  set_armor_params("other|good",0,-50,0);
  set_armor_params("other|light",0,-25,0);
  set_armor_params("other|earth",0,25,0);
  set_armor_params("other|water",0,25,0);
  set_armor_params("other|magical",0,25,0);
  set_armor_params("other|fire",0,25,0);
  move_object(clone_object("/players/sami/area/coinarea/obj/barter/projector.c"),this_object());
  
  move_object(clone_object("/players/sami/area/coinarea/obj/wep/scythe.c"),this_object());
init_command("wield scythe");
move_object(clone_object("/players/sami/area/coinarea/obj/armor/ring.c"),this_object());
init_command("wear ring");
  
  set_multi_cast(2);

  add_spell("Scythe_stab",
  ""+HIK+"#MN#"+NORM+" raises his "+BOLD+"scythe"+NORM+" and brings it down, lodging it into your "+HIC+"spine"+NORM+".\n",
  " "+HIK+"#MN#"+NORM+" cuts deep into the spine of "+HIR+"#TN#"+NORM+".\n",
  40,({15,15}),({"other|evil","other|dark"}),1);

  add_spell("Scythe_sweep", 
   ""+HIK+"#MN# "+HIR+"S W E E P S"+NORM+"his scythe into your"+HIR+" L E G"+NORM+".\n",
  ""+HIK+"#MN#"+HIR+" S W E E P S"+NORM+" his scythe into "+HIG+"#TN#'s leg.\n",
  30,({15,15}),({"other|dark","other|evil"}),1);
 
 add_spell("cold_embrace",
  ""+HIK+"#MN#"+NORM+" reaches out and "+MAG+"Pulverises"+NORM+" you with his "+BOLD+"cold embrace"+NORM+".\n",
  ""+HIK+"#MN#"+NORM+" reaches out and "+MAG+"Pulverises"+NORM+" #TN# with his "+BOLD+"cold embrace"+NORM+".\n",
  30,({30,30}),({"other|dark","other|evil"}),1);
  
  add_spell("Heal_spell",
    ""+HIK+"#MN#"+NORM+" absorbs"+BOLD+" SOULS"+NORM+" that escape his Scythe.\n",
    ""+HIK+"#MN#"+NORM+" absorbs"+BOLD+" SOULS"+NORM+" and feels"+HIR+" rejuvenated"+NORM+".\n",
   65,"20-30",0,3,"heal_me");
   
    add_spell("touch_of_death",
  ""+HIK+"#MN#"+NORM+" "+MAG+"Grasps"+NORM+" you with his "+BOLD+"Touch of Death"+NORM+".\n",
  ""+HIK+"#MN#"+NORM+" "+MAG+"Grasps"+NORM+" #TN# with his "+BOLD+"Touch of Death"+NORM+".\n",
  30,({30,30}),({"other|magical","other|evil"}),1);
  
  add_spell("Spirits_of_the_dead",
  ""+HIK+"#MN#"+NORM+" summons "+HIR+"spirits"+NORM+" that "+BOLD+"D E V A S T A T E"+NORM+" you.\n",
  ""+HIK+"#MN#"+NORM+" summons "+HIR+"spirits"+NORM+" that "+BOLD+"D E V A S T A T E"+NORM+" #TN#.\n",
  30,({30,30}),({"other|magical","other|evil"}),1);
  
  add_spell("Fatal_fury",
  ""+HIK+"#MN#"+NORM+" unleashes a series of "+HIR+"--==SLASHES==--"+NORM+" that "+BOLD+"D E S T R O Y"+NORM+" you.\n",
  ""+HIK+"#MN#"+NORM+" unleashes a series of "+HIR+"--==SLASHES==--"+NORM+" that "+BOLD+"D E S T R O Y"+NORM+" #TN#.\n",
  30,({20,20}),({"other|magical","other|physical"}),1);
     } 
    heart_beat() {
  object       ob;
  ::heart_beat();

  if(!attacker_ob) {
    return;
  }}

heal_me( object target, object room, int damage ) {
  int amt;
  amt = 50 + random(80);
  damage = 25 + random(25);
  set_hp_bonus( hp_bonus + amt );
  heal_self(amt);

   } 
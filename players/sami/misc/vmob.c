inherit "/obj/monster.c";
#include "/sys/lib.h"
#include <ansi.h>
#define tpn this_player()->query_name()
#define ATT USER->query_attack()

object evil;

reset(arg) {
  ::reset(arg);
  if(arg) return;	
  set_name("vark");
  set_alias("shadowmancer");
  set_race("hologram");
  set_short("Vark, "+HIK+"Shadowmancer"+NORM+" of "+HIY+"legend"+NORM+"");
  set_long(
    " A shadowy figure, cloaked in a seamless tunic that seems to drape to the floor.\n"+
    " A deformed hand grasps a magnificent scepter; forged from some unknown alloy. Red\n"+
	" eyes glare from underneath the hood. He appears to be Extremely "+HIR+"Dangerous"+NORM+".\n");
  set_level(24);
  set_hp(1+random(5));
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
  
evil=clone_object("/players/sami/misc/twep2.c");
        move_object(evil, this_object());
move_object(clone_object("/players/sami/area/coinarea/obj/armor/ring.c"),this_object());
init_command("wear ring");
  
  set_multi_cast(2);

  add_spell("Scepter_pummel",
  ""+HIK+"#MN#"+NORM+" pummels you with his "+HIC+"scepter"+NORM+".\n",
  " "+HIK+"#MN#"+NORM+" pummels "+HIR+"#TN#"+NORM+" with their scepter.\n",
  15,({15,15}),({"other|evil","other|dark"}),1);

  add_spell("Scepter_sweep", 
   ""+HIK+"#MN# "+HIR+"S W E E P S"+NORM+"his scepter into your"+HIR+" L E G"+NORM+".\n",
  ""+HIK+"#MN#"+HIR+" S W E E P S"+NORM+" his scepter into "+HIG+"#TN#'s leg.\n",
  15,({10,15}),({"other|dark","other|evil"}),1);
 
 add_spell("cold_embrace",
  ""+HIK+"#MN#"+NORM+" reaches out and "+MAG+"Pulverises"+NORM+" you with his "+BOLD+"cold embrace"+NORM+".\n",
  ""+HIK+"#MN#"+NORM+" reaches out and "+MAG+"Pulverises"+NORM+" #TN# with his "+BOLD+"cold embrace"+NORM+".\n",
  10,({10,10}),({"other|dark","other|evil"}),1);
  
  add_spell("Heal_spell",
    ""+HIK+"#MN#"+NORM+" absorbs"+BOLD+" S O U L S"+NORM+" that escape his Scepter.\n",
    ""+HIK+"#MN#"+NORM+" absorbs"+BOLD+" SOULS"+NORM+" and feels"+HIR+" rejuvenated"+NORM+".\n",
   15,"20-30",0,3,"heal_me");
   
    add_spell("touch_of_death",
  ""+HIK+"#MN#"+NORM+" "+MAG+"Grasps"+NORM+" you with his "+BOLD+"Touch of Death"+NORM+".\n",
  ""+HIK+"#MN#"+NORM+" "+MAG+"Grasps"+NORM+" #TN# with his "+BOLD+"Touch of Death"+NORM+".\n",
  10,({10,10}),({"other|magical","other|evil"}),1);
  
  add_spell("Spirits_of_the_dead",
  ""+HIK+"#MN#"+NORM+" summons "+HIR+"spirits"+NORM+" that "+BOLD+"D E V A S T A T E"+NORM+" you.\n",
  ""+HIK+"#MN#"+NORM+" summons "+HIR+"spirits"+NORM+" that "+BOLD+"D E V A S T A T E"+NORM+" #TN#.\n",
  15,({10,10}),({"other|magical","other|evil"}),1);
  
  add_spell("Fatal_fury",
  ""+HIK+"#MN#"+NORM+" unleashes a series of "+HIR+"--==SLASHES==--"+NORM+" that "+BOLD+"D E S T R O Y"+NORM+" you.\n",
  ""+HIK+"#MN#"+NORM+" unleashes a series of "+HIR+"--==SLASHES==--"+NORM+" that "+BOLD+"D E S T R O Y"+NORM+" #TN#.\n",
  10,({10,10}),({"other|magical","other|physical"}),1);
     } 
    heart_beat() {
  object       ob;
  ::heart_beat();

  if(!attacker_ob) {
    return;
  }}

heal_me( object target, object room, int damage ) {
  int amt;
  amt = 5 + random(10);
  damage = 10 + random(10);
  set_hp_bonus( hp_bonus + amt );
  heal_self(amt);

   } 
   
    monster_died() {
  if( attacker_ob && evil ) {
    evil->set_binder( attacker_ob->query_real_name() );
    tell_room( environment(), ""+HIW+"A flash of light flashes from the weapon as it is soulbound to "+ attacker_ob->query_name()+".\n"+NORM );
  }}
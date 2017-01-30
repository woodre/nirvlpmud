inherit "/obj/monster.c";
#include <ansi.h>
#define tpn this_player()->query_name()
#include "/sys/lib.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;
	
  set_name("simon");
  set_alias("belmont");
  set_race("hologram");
  set_short(""+HIY+"Simon Belmont"+NORM+"");
  set_long(
    " This hero is clad in a black and orange leather suit with an\n"+
    " small metal belt around his waist. Armed with a extremely long\n"+
	" whip, this hero is on the hunt for Dracula.\n");
  set_level(23);
  set_hp(1600+random(700));
  set_al(-800);
  set_heal(10,10);
  set_ac(30+random(4));
  set_wc(45);
  set_aggressive(0);
   move_object(clone_object("/players/sami/area/coinarea/obj/armor/sandles.c"),this_object());
   init_command("wear boots");
  move_object(clone_object("/players/sami/area/coinarea/obj/barter/projector.c"),this_object());

move_object(clone_object("/players/sami/area/coinarea/obj/wep/whip.c"),this_object());
init_command("wield whip");  
 set_multi_cast(5);
 
 add_spell("Simon_whip",
  ""+HIK+"#MN#"+NORM+" wraps his whip around your leg and you "+HIR+"C R A S H"+NORM+" into the ground.\n",
  ""+HIK+"#MN#"+NORM+" wraps his whip around #TN#'s leg and #TN# "+HIR+"C R A S H E S"+NORM+" into the ground.\n",
  50,({25,25}),({"other|earth","other|good"}),1);

  add_spell("roundhouse_kick", 
   ""+HIK+"#MN# "+NORM+" delivers a deadly"+HIB+" roundhouse"+NORM+" to your "+HIR+" abdomen"+NORM+".\n",
  ""+HIK+"#MN# "+NORM+" delivers a deadly"+HIB+" roundhouse"+NORM+" to #TN#'s "+HIR+" abdomen"+NORM+".\n",
  30,({25,25}),({"other|light","other|good"}),1);
  
  add_spell("knife_throw", 
   ""+HIK+"#MN# "+NORM+" throws a knife with deadly"+HIB+" precision "+NORM+" at your "+HIR+" chest"+NORM+".\n",
  ""+HIK+"#MN# "+NORM+" throws a knife with deadly"+HIB+" precision "+NORM+" at #TN#'s "+HIR+" chest"+NORM+".\n",
  30,({15,15}),({"other|good","other|physical"}),1);
  
   add_spell("holy_cross", 
   ""+HIK+"#MN# "+NORM+" uses the Belmont's ultimate"+HIB+" Holy Cross "+HIR+" D E S T R O Y I N G"+NORM+" you.\n",
  ""+HIK+"#MN# "+NORM+" uses the Belmont's ultimate"+HIB+" Holy Cross "+HIR+" D E S T R O Y I N G"+NORM+" #TN#.\n",
  30,({40,40}),({"other|good","other|light"}),1);
  
  add_spell("holy_acid_water", 
   ""+HIK+"#MN# "+NORM+" tosses a mix of"+HIG+" Acid"+NORM+" and"+HIC+" Holy Water"+NORM+" at you.\n",
  ""+HIK+"#MN# "+NORM+" tosses a mix of"+HIG+" Acid"+NORM+" and"+HIC+" Holy Water"+NORM+" at #TN#.\n",
  30,({20,20}),({"other|good","other|poison"}),1);
  
  add_spell("axe_axe", 
   ""+HIK+"#MN# "+NORM+" tosses a 8-bit "+HIG+" AXE"+NORM+" and hits you in the"+HIC+" CHEST"+NORM+".\n",
  ""+HIK+"#MN# "+NORM+" tosses a 8-bit "+HIG+" AXE"+NORM+" and hits #TN# in the"+HIC+" CHEST"+NORM+".\n",
  30,({20,20}),({"other|magical","other|good"}),1);
  
   } 

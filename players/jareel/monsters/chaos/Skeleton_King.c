inherit "/obj/monster";
#include "/players/jareel/define.h"

reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name("The Skeleton King");
  set_alt_name("skeleton");
  set_alias("king");
  set_race("chaos");
  set_short(HIW+"The Skeleton King"+NORM+"");
  set_long(
    "The frail gathering of bones seem to move without any\n"+
    "form of muscle structure.  Its hollow skull has a darkness\n"+
    "in its eye holes that seem to peer right into you..\n");

  set_level(25);
  set_res(50);
  set_ac_bonus(25);
  set_ac(15);
  set_wc(55);
  set_hp(1000);
  set_heal(20,2);
  set_al(-1000);
  set_aggressive(1);
  set_assist("/players/jareel/monsters/chaos/skeleton.c", 10, 5, 10);
   
  add_spell(
    "King Glare",
	  "The "+HIW+"Skeleton King "+NORM+" glares at #TN#!!!!!!!!!!\n\
	                       "+HIK+"you feel light headed........"+NORM+"\n",
      "The "+HIW+"Skeleton King "+NORM+" glares at #TN#!!!!!!!!!!\n",
    45,70,"other|mental");
	
  add_spell(
    "King Slash",
	  "The "+HIW+"Skeleton King "+NORM+" slashes at #TN#\n",
      "The "+HIW+"Skeleton King "+NORM+" Slashes at #TN#\n",
    45,70,"magical");
	
  add_spell(
    "King Doom",
	  "The "+HIW+"Skeleton King "+NORM+" Unleashes a death howl at #TN#\n",
	  "The "+HIW+"Skeleton King "+NORM+" Unleashes a death howl at #TN#\n",
    10,150,"other|evil");
	
}





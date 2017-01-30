/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2004 Forbin
//                  All Rights Reserved.
//  Realm:        The Ruins (/players/forbin/realms/ruins/)
//  Function:     NPC
//  Create Date:  unknown
//  Last Edit:    2004.07.22 -Forbin
//  Notes:        Adapted heavily from original mob
//                  Original Copyright (c) Maledicta@Nirvana
//  Approval:     Fred 2004.07.24
//  Notable Changes:  
//    2004.07.12 -new spell attacks added, [Forbin]
//    2004.07.22 -added #defines for wc/ac bonuses [Forbin] 
*/ 

#include "/players/forbin/realms/ruins/ruinsdefine.h"
#include "/players/forbin/logging.h"
#pragma combine_strings
inherit "/players/vertebraker/closed/std/monster.c";

#define SHADOWD HIW+"S"+NORM+WHT+"h"+HIW+"a"+NORM+WHT+"d"+HIW+"o"+NORM+WHT+"w "+NORM+WHT+"D"+HIW+"e"+NORM+WHT+"m"+HIW+"o"+NORM+WHT+"n"+NORM

#define WEAKEN_WC_BONUS 3 /* see function header for calculations */
#define WEAKEN_AC_BONUS 4 /* see function header for calculations */
#define SUMMON_DEMON_WC_BONUS 30 /* see function header for calculations */

id(str) { return (::id(str) || str == "archangel" || str == "angel" ||
                               str == "demon"); }

reset(arg)  {
  ::reset(arg);
  if(arg) return;
  move_object(clone_object(OBJ+"newscloak.c"), this_object());
  move_object(clone_object(OBJ+"sshield.c"), this_object());
  move_object(clone_object(OBJ+"swhip.c"), this_object()); 
  command("wield weapon", this_object());
  command("wear shield", this_object());  
  command("wear cloak", this_object());  
  set_name("Archangel of Shadows");
  set_alt_name("archangel of shadows");
  set_short(HIK+"Archangel of Shadows"+NORM);
  set_long(
    "  Standing before you at over 7 feet tall, this towering figure is\n"+
    "wrapped in a long flowing cloak.  His gangly arms and legs covered\n"+
    "in some moth eaten black cloth.  His skin is pasty white with sores\n"+
    "covering it in numerous places.  The face looks like something that\n"+
    "has been dead for weeks - bloated, chalky white and drooping in the\n"+
    "cheeks and under the eyes.  But the eyes catch your attention, and you\n"+ 
    "understand why this thing is the Lord of the Shadows.  Within their\n"+
    "depths you see a darkness so complete you fear you might fall into\n"+
    "them and lose the light of the world forever.  A huge shield is\n"+
    "strapped to his right arm; a long slender whip is held in the left.\n"+
    HIW+"Powerful shadows swirl about this being of darkness.\n"+NORM); 
  set_level(21);
  set_hp(600);
  set_al(-random(1000));
  set_wc(34);
  set_wc_bonus(WEAKEN_WC_BONUS + SUMMON_DEMON_WC_BONUS);
  set_ac(18);
  set_ac_bonus(WEAKEN_AC_BONUS);
  set_aggressive(1);
  set_heal(6,3);
  set_dead_ob(this_object());
  set_chat_chance(5);
    load_chat("The Lord of Shadows stands staring at you his lips turned up in an\n"+
              "evil grin.\n");
    load_chat("A shadow near you flickers slightly.\n");
  set_a_chat_chance(15);
    load_a_chat("The "+HIK+"Lord of Shadows"+NORM+" deflects your attack!\n");
/*
//  SPELL ATTACKS:
//  Flick :::::::::: 20% chance 15-30 physical damage to random player, 
//  Weaken ::::::::: 15% chance 5-15 magical damage to random player, 
//                    also lowers the targets ac & wc 
//  Shadowdeamon ::: 15% chance no damage to random player, 
//                    clones a Shadowdemon to attack for 3 rounds
*/
  add_spell("flick",
    "\tThe $HK$Archangel of Shadows$N$ flicks his whip at you.\n"+
    "\tYou feel a burst of pain as it draws blood!\n",
    "The $HK$Archangel of Shadows$N$ flicks his whip at #CTN#,\n"+ 
    "drawing deep lines of blood!\n",
    20, "15-30", "physical", 6);
  add_spell("weaken",
    "\n\n\tThe $HK$Archangel of Shadows$N$ points at you.\n"+
    "\t\t$HW$Shadows$N$ rise up from beneath and attack you!\n",
    "The $HK$Archangel of Shadows$N$ points as #CTN#.\n"+
    "$HW$Shadows$N$ rise up and attack #TO#!\n",
    15, 20, "magical", 6, "weaken");
  add_spell("shadowdemon",
    "\n\tThe $HK$Archangel of Shadows$N$ conjures a "+SHADOWD+" to attack you.\n\n",
    "The $HK$Archangel of Shadows$N$ conjures a "+SHADOWD+" to attack #CTN#.\n",
    15, 0, "physical", 6, "summon_demon");
}

init() {
  ::init();
  add_action("no_move", "west");  
}       
      
no_move() {
  if(!(this_player()->query_ghost())) {  
    write(
      HIR+"As you try and leave the "+HIK+"Archangel of Shadows"+NORM+" lashes out with his whip\n"+
      "entangling you!  You cannot escape!\n"+NORM);  
    return 1;
  }
  return;
}

/* 
//  ***********************************************************************
//  Function:    weaken
//  Description: clones a timed object to weaken a players ac & wc lowers 
//               players wc avg of 3.5 and ac avg of 3 for avg 7 rounds
//  Arguments:   object target, object room, int damage
//  WC_Bonus:    3 (given because of decreases in players' ac)
//    .15 (chance) * 21 (avg ac drop * avg round) = 3.1 = 3
//  AC_Bonus:    4 (given because of decreases in players' wc)
//    .15 (chance) * 24.5 (avg wc drop * avg round) = 3.7 = 4
//  ***********************************************************************
*/

weaken(object target, object room, int damage) {
  object weakenob;
  int time, negwc, negac;
  if(!present("shadow_weaken_object", target)) {
    time = (5 + random(5));
    negwc = (2 + random(4));
    negac = (2 * random(3));
    weakenob = clone_object(OBJ+"shadow_weaken.c");
    move_object(weakenob, target);
    weakenob->start_weaken(target, time, negwc, negac);
  }
}

/* 
//  ***********************************************************************
//  Function:    summon_demon
//  Description: clones a mob to attack a random player for 3-6 hbs
//               monster attacks each round with 10-35 magical damage
//               so it deals 30-210 damage or 135 average damage
//  Arguments:   object target, object room, int damage
//  WC_Bonus:    30
//    .15 (chance) * 135 (avg dmg) = 20.25 * 1.5 (dmg type) = 30.4 = 30
//  ***********************************************************************
*/

summon_demon(object target, object room, int damage) {
  object demon;
  demon = clone_object(NPC+"shadowdemon.c");
  move_object(demon, environment(this_object()));
  demon->attack_object(target);
  return 1;
}

monster_died() {
  object corpse;
  corpse = present("corpse", environment());   
#ifdef BIGKILLLOG
  mon_log(BIGKILLLOG);
#endif
  tell_room(environment(this_object()),
    "The Lord of Shadows gives a last silent cry as he falls to the ground in\n"+
    "defeat.  His body dissolves like a whisp of shadow in the light.\n"); 
  if(corpse) destruct(corpse);
  return 1; 
}



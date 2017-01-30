/*
 *  Created:      Forbin@Nirvana
 *  Copyright:    Copyright (c) 2004 Forbin
 *                  All Rights Reserved.
 *  Realm:        The Ruins (/players/forbin/realms/ruins/)
 *  Function:     NPC
 *  Create Date:  unknown
 *  Last Edit:    2004.07.12 -Forbin
 *  Notes:        Adapted heavily from original mob
 *                  Original Copyright (c) Maledicta@Nirvana
 *  Notable Changes:    
*    2004.07.12 -new spell attacks added, gloves updated
 */ 

#include "/players/forbin/realms/ruins/ruinsdefine.h"
#include "/players/forbin/logging.h"
#pragma combine_strings
inherit "/players/vertebraker/closed/std/monster.c";
#define DEBUG

string *Drained;

id(str) { return (::id(str) || str == "archangel" || str == "angel" ||
                               str == "death" || str == "demon"); }

reset(arg)  {
  ::reset(arg);
  if(arg) return;
  
  Drained = ({ });
  move_object(clone_object(OBJ+"gloves.c"), this_object());
  command("wield gloves", this_object());
  set_name("Archangel of Death");
  set_alt_name("archangel of death");
  set_short(HIR+"Archangel "+HIK+"of Death"+NORM);
  set_long(
    "  You stand before a being of great power.  On its hands are large dark\n"+
    "steel gloves, wicked spikes capping the knuckles and fingers.  Great\n"+
    "wings spring from its back, their appearance that of a bat.  You look\n"+
    "carefully at its face and see that it is jet black with eyes of pure\n"+
    "white.  Its entire body is covered with a black robe which is decorated\n"+
    "with magical runes of protection.  This being carries the stench of\n"+
    "death with it.\n");
  set_level(22);
  set_heal(5,3);
  set_hp(750);
  set_al(-1000);
  set_wc(40);
  set_ac(22);
  set_ac_bonus(21 + 4);
  set_aggressive(0);
  set_dead_ob(this_object());
  set_chat_chance(5);
    load_chat("The stench of death fills the room.\n");
    load_chat("Death looks down at you and sneers.\n");
  set_a_chat_chance(15);
    load_a_chat("Death says: The longer you fight me, the stronger I get!\n");
    load_a_chat("Archangel of Death cackles maniacally!\n");
  set_multi_cast(1);
/*
 *  SPELL ATTACKS:
 *  Feed :::: 30% chance 20-30 other|forbin damage to random attacker,
 *             heals monster for damage done, possible 1 time loss of attribute      
 *  Punch ::: 15% chance 10-25 physical damage to random player attacker, 
 *  Stench :: 10% chance 0-44 other|poison damage to all attackers, 
 */
  add_spell("feed",
    "\n         The $HR$Archangel$HK$ of Death$N$ feeds upon you.\n\n"+
    "You feel the life drain from your body as $HK$Death$N$ touches you!\n\n",
    "\nThe $HR$Archangel$HK$ of Death$N$ feeds upon #CTN#.\n\n",
    30, "20-30", "other|forbin", 5, "feed_me");
  add_spell("punch",
    "\nThe $HR$Archangel$HK$ of Death$N$ lashes out with his armored fists, driving them into you!\n\n",
    "\nThe $HR$Archangel$HK$ of Death$N$ lashes out with his armored fists, driving them into #CTN#!\n\n",
    20, "10-25", "physical", 6);
  add_spell("stench",
    "\t$HG$  Your lungs burn from the toxic cloud.$N$\n\n",
    "The $HR$Archangel$HK$ of Death$N$ speaks in a foul-sounding demonic tongue.\n"+  
    "\n\t$G$A rotten stench seeps up from the ground.$N$\n",
    10, 45, "other|poison", 1);
}

init() {
  ::init();
  if(this_player()->query_level() < 15){
  write(
    "\n\n\nThe "+HIR+"Archangel"+HIK+" of Death"+NORM+" looks down at you and says:\n"+
    "\"Foolish little mortal, I'd not be here if I were you.  You WILL die.\"\n");
  return 1;
  }             
}

/* 
 *  ***********************************************************************
 *  Function:    feed_me
 *  Description: call_out for delayed message & heal to mob
 *  Arguments:   object target, object room, int damage
 *  ***********************************************************************
 */

feed_me(object target, object room, int damage) {
#ifdef DEBUG
    mdmsg("feed_me() called :: target: "+target->query_name()+" dmg: "+damage);
#endif
    call_out("feed_message", 3, ({ target, damage, room }));
  }
}

/* 
 *  ***********************************************************************
 *  Function:    feed_message
 *  Description: heals mob for damage done from feed spell, possible loss
 *               of one pt from any single target's stat
 *  Arguments:   mixed array of object target and int damage
 *  AC_Bonus:    21 + 4
 *    .30 (chance) * 35 (avg heal) = 10.5 * 2 = 21 = 21
 *    +4 added in to account for possible stat drain
 *  ***********************************************************************
 */

feed_message(mixed *arg) {
  object food;
  object mob;
  int la, ok, i;
  int healamt;
  string las;  
  food = arg[0];
  healamt = arg[1];
  mob = present("archangel of death", arg[2]);
  if(!mob) return 0; 
#ifdef DEBUG
  mdmsg("feed_message() called :: Target: "+food->query_name()+" Healamt: "+healamt);
  mdmsg("Pre HP :: "+this_object()->query_hp());
#endif
  this_object()->heal_self(healamt);
#ifdef DEBUG
  mdmsg("Post HP :: "+this_object()->query_hp());
#endif  
  tell_object(food,
    RED+"Blood red energy"+NORM+" flows from you into the "+HIR+"Archangel"+HIK+" of Death"+NORM+".\n");
  tell_room(environment(food),
    RED+"Blood red energy"+NORM+" flows from "+food->query_name()+" into the "+HIR+"Archangel"+HIK+" of Death"+NORM+".\n", ({ food }));
  if(!random(13)) {
    if(!query_drained(food->query_real_name())) {
#ifdef DEBUG
      mdmsg("stat drain");
#endif      
      ok = 0;
      i=0;
      while (ok < 1) {
        la = random(10);
        i=i+1;
        if(i>70) return 1;
        if (la == 10) return 1;
        if (la == 8) las = "charisma";
        if (la == 9) las = "dexerity";
        if (la == 7) las = "strength";
        if (la == 6) las = "will_power";
        if (la == 5) las = "magic_aptitude";
        if (la == 4) las = "piety";
        if (la == 3) las = "stamina";
        if (la == 2) las = "stealth";
        if (la == 1) las = "luck";
        if (la == 0) las = "intelligence";
        if (call_other(food, "query_attrib", extract(las,0,2)) > 1)
        ok = 1;
      }
      if(las == "will_power") las = "will power";
      if(las == "magic_aptitude") las = "magic";
#ifdef DEBUG
      mdmsg(food->query_name()+": "+las+" lowered one point");
#endif      
      tell_object(food,
        "You scream out in PAIN as you feel part of your soul torn away!\n"+
        "                "+HIW+"You loose a point of "+las+"."+NORM+"\n");
      if(las == "will power") las = "will_power";
      if(las == "magic") las = "magic_aptitude";        
      call_other(food, "raise_" + las, -1);        
      tell_room(food,
        food->query_name()+" screams out in pain as part of "+food->query_possessive()+" soul is torn away!\n");
    add_drained(food->query_real_name());
    }
  }
}

/* 
 *  ***********************************************************************
 *  Function:    add_drained, sub_drained, query_drained
 *  Description: these are used to prevent players from loosing more than
 *               1 pt of any one stat when feed_me/feed_message are called
 *  Arguments:   string of object's name
 *  ***********************************************************************
 */

add_drained(string realname) {
  if(!query_drained(realname)) return Drained += ({ realname, });
    return 0;
}

sub_drained(string realname) {
  if(query_drained(realname)) return Drained -= ({ realname, });
    return 0;
}

query_drained(string realname) {
  if(!Drained || !sizeof(Drained)) return 0;
  if(index(Drained, realname) > -1) return 1;
  return 0;
}
  
monster_died() {
  object corpse;
  corpse = present("corpse", environment());   
#ifdef BIGKILLLOG
  mon_log(BIGKILLLOG);
#endif
  tell_room(environment(this_object()),
    "You defeat Death and watch as his material form disintegrates into\n"+
    "a fine mist, soon evaporating into nothing.\n"+
    "Death's gloves fall to the ground, their steel armor ringing\n"+
    "loudly as they strike.\n");
  if(corpse) destruct(corpse);
  return 1; 
}

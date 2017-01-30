/*****************************************************************************
 *      File:                   mob_funcs.c
 *      Function:               BWO mob special functions
 *      Author(s):              Sparrow@Nirvana
 *      Copyright:              Copyright (c) 2006 Sparrow 
 *                              All Rights Reserved.
 *      Source:                 03/14/2006
 *      Notes:                  Thanks to Fred, Earwax, and Pavlik for helping
 *                              with these functions.
 *      Change History:         03/15/06 Earwax: gut_punch() added check for 
 *                              attacker.
 *                              03/15/06 Sparrow: gut_punch() added check for 
 *                              bruise and changed emotes. 
 *                              03/15/06 Sparrow: Began adding standardized
 *                              headers for file and functions.
 *                              03/18/06 Sparrow: Removed random from funcs
 *                              to be used with mob spells.
 *                              03/20/06 Sparrow: Added true_darkness function
 *                              03/20/06 Sparrow: Added new_target function
 *                              03/20/06 Earwax: Fixed new_target function
 *                              03/21/06 Sparrow: Added check for ranger guild
 *                              on disarm and weapon_break. Due to the nature
 *                              of the ranger weapon, it would actually remove
 *                              their guild object and place on ground. fixed
 *                              03/22/06 Sparrow: Added check for fallen to
 *                              determine if they are wielding a weapon (which
 *                              means disarmable) or bare hands (guild object
 *                              not disarmable)
 *                              03/22/06 Sparrow: Removed guild check all-
 *                              together for weapon_break and disarm. Now
 *                              checking tomake sure that weapon is drop(0)
 *                              3/23/06 Sparrow: Heh, removed drop(0) and 
 *                              replaced it with id("GI")
  ****************************************************************************/
 
#include <ansi.h>
#define MOVE_INTERVAL 100
object Target;

/* 
 * Function name: random_sex()
 * Description:   This function uses random() to randomly select a sex
 *                for a creature.
 * Arguments:     None
 * Returns:       string
 */

string
random_sex(){
  switch(random(8)) {
    /* 62.5% chance of being male */
    case 0: case 1: case 2: case 3: case 4:
      return "male";
    break;
    case 5: case 6: case 7:
      return "female";
    break;
    default:
      return "male";
  }
}


/* Function name: random_race()
 * Description:   This function uses random() to generate a random
 *                race for the mob.
 * Arguments:     None
 * Returns:       string
 */
string random_race(){
  /* random race */
  switch(random(20)) {
    /* 25% chance of being human */
    case 0: case 1: case 2: case 3: case 4:
      return "human";
    break;
    /* 20% chance of being elven */
    case 5: case 6: case 7: case 8:
      return "elf";
    break;
    /* 15% chance of being  dwarven */
    case 9: case 10: case 11:
      return "dwarf";
    break;
    /* 15% chance of being orcish */
    case 12: case 13: case 14:
      return "orc";
    break;
    /* 10% chance of being a demon */
    case 15: case 16:
      return "demon";
    break;
    /* 10% chance of being a cyborg */
    case 17: case 18:
      return "drow";
    break;
    case 19:
    /* 5% chance of being a celestial being */
      return "celestial";
    break;
    default:
      return "human";
  }
}

/* 
 * Function name: gut_punch()
 * Description:   This function checks for a prego attacker, checks to
 *                see if the miscarriage bruise exists on attacker, if
 *                not, clones miscarriage to attacker.
 *                for a creature.
 * Arguments:     att - object
 * Returns:       integer
 */
gut_punch(object att){
  object ob;
  string obname, attname, bruises;
  if (att && att->query_pregnancy()) {
    bruises = present("bruise",att);
    if(!bruises){
      ob = clone_object("/players/sparrow/areas/bwo/obj/miscarriage.c");
      move_object(ob, att);
      obname = capitalize(this_object()->query_real_name());
      attname = capitalize(att->query_real_name());
      say("\n"+HIM+" ~ "+HIW+obname+" punches "+attname+ "hard in the stomach!\n"+
        HIM+" ~ "+HIK+"DARK ENERGY"+HIW+" pours out of "+obname+"'s body!\n\n"+NORM);
      tell_object(att,HIM+" ~ "+HIW+"\nYou are punched "+HIR+"HARD"+HIW+
        " in the stomach, you feel "+HIK+"dark energies"+HIW+
        " coursing through your womb!\n\n"+NORM);
      return 1;
    }
  }
  return 0;
}

/* Function name: disarm()
 * Description:   This function checks for an attacker, if the attacker
 *                is wielding a weapon. Disarm unwields the weapon and 
 *                places it in room. 
 * Arguments:     att - object
 * Returns:       integer
 */
 
disarm(object att){
  object att_wep;
  string guildname, wepname;
  /* percentage determined by spell */
  if(att){
    if(att && att->query_weapon()){
      att_wep = att->query_weapon();
      wepname = att_wep->query_name();
      if(!att_wep->id("GI")){      
        call_other(att, "stop_wielding");
        move_object(att_wep, environment(att));
        tell_object(att,HIM+" ~ "+HIR+"\nThe Monk knocks your "+wepname+HIR+" out of your hands!\n\n"+NORM);
        return;
      }
    }
  }
  return;
}

/* Function name: weapon_breaker()
 * Description:   This function checks for an attacker, if the attacker
 *                is wielding a weapon this should break it
 * Arguments:     att - object
 * Returns:       integer
 */

weapon_breaker(object att) {
  string wepname, guildname;
  object att_wep;
  if(att){
    /* Percentage determined by spell */
    if(att && att->query_weapon()){
      att_wep = att->query_weapon();
      if(!att_wep->id("GI")){  
        wepname = att_wep->query_name();
        tell_object(att, HIM+" ~ "+HIG+"The monk slams your "+wepname+"$HIG$ back in your face!\n"+
          HIM+" ~ "+HIG+"You hear a loud CRACK!!!!"+NORM);
        call_other(att_wep, "weapon_breaks");
        return;
      }
    }
  }
  return;
}

/* 
 * Function name: true_darkness()
 * Description:   This function will clone globe of true darkness
 *                to the mob.
 * Arguments:     None
 * Returns:       void
 */
void
true_darkness(){
  object globe,ob;
  globe = present("true_darkness",this_object());
  if (!globe) {
      tell_room(environment(this_object()),
        HIM+" ~ "+HIK+"The Monk kneels down and summons a Globe of "+
        HIK+"True Darkness"+HIW+"!\n"+NORM);
      ob = clone_object("/players/sparrow/areas/bwo/obj/true_darkness.c");
      move_object(ob, this_object());
      return;
  }
  return;
}

/*
 * Function name: new_target()
 * Description:   This function is used to change the focus of the
 *                attacking mob.
 * Arguments:     object att
 * Returns:       void
 */
void
new_target(object att){
  /* Check to see if current target is set */
  /* Changin it to test with different add spell variable
  if(!Target){
    Target = (object)this_object()->query_attack(); 
  }
  
  if(Target == att) { 
    tell_object(Target, "The monk sneers at you as you are knocked back!\n");
    return;
  } */
  if(!att) { 
    say(HIW+"["+HIR+"ERROR"+HIW+"]"+HIG+" ATTACKER OBJECT NOT FOUND!\n"+NORM);
    return; 
  }
  this_object()->attack_object(att);
  Target = att;
  tell_object(Target, HIM+" ~ "+HIR+"You realize that you are now the focus of the battle!\n"+NORM);
  tell_room(environment(Target), 
    HIM+" ~ "+HIR+capitalize((string)Target->query_real_name())+
    " is now the recipient of the monks wrath!\n"+NORM);
  return;
}

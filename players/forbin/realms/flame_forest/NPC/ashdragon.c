/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2005 Forbin
//                  All Rights Reserved.
//  Realm:        Flame Forest
//  Function:     NPC
//  Create Date:  2005.12.04
//  Last Edit:    2005.12.04 -Forbin
//  Notable Changes:            
*/ 

#include "/players/forbin/realms/flame_forest/ffdefine.h"
#include "/players/forbin/logging.h"
#pragma combine_strings
inherit "/players/vertebraker/closed/std/monster.c";

int HealNum;

#define HEAL_HP_BONUS 3300		   /* heals an average of 3300 hps */
#define CALL_BLIND_WC_BONUS 8      /* see function header for calculations */
#define CALL_BLIND_AC_BONUS 5      /* see function header for calculations */
#define CALL_HEAL_TWO_AC_BONUS 10  /* see function header for calculations */

id(str) 
{ 
  return (::id(str) || str == "clath" || str == "dragon"  
                    || str == "ash dragon"  || str == "ashdragon" 
                    || str == "clath, the ash dragon"); 
}

reset(arg) 
{
  ::reset(arg);
  if(arg) return;

  message_hit = 
  ({ "D E S T R O Y S","",
     "LEVELS"," with a swish of his tail",
     "RENDS"," with his claws, showering the room with "+RED+"BLOOD"+NORM,
     "bites"," very hard",
     "bites"," hard",
     "hits"," hard with his head",
     "scratches"," with his talons",
  });

  HealNum = 3;
  
  set_name(HIK+"Clath"+NORM);
  set_race("dragon");
  set_gender("male");
  set_short(HIK+"Clath, the Ash Dragon"+NORM);
  set_long(
    "\n");  
  set_level(28);
  set_hp(2000);
  set_hp_bonus(HEAL_HP_BONUS);
  set_al(-666);
  set_wc(60);
  set_wc_bonus(CALL_BLIND_WC_BONUS);  
  set_ac(25);
  set_ac_bonus(CALL_BLIND_AC_BONUS + CALL_HEAL_TWO_AC_BONUS);  
  set_dead_ob(this_object());  
  set_chat_chance(15);
    load_chat("");
  set_a_chat_chance(20);
    load_a_chat("");
/* 
////////////////////////////////////////////////////////////////////////////
// AcidArrow
//   10% chance of 50-100 physical damage to main attacker
// Scratch 
//   8% chance of 5-35 physical damage to random attacker
// AshBloom
//   5% chance of 20-50 other|poison damage to main attacker
//   calls additional 15-40 other|poison damage to all player attackers and
//   clones object that lowers all attackers WC for several rounds
////////////////////////////////////////////////////////////////////////////
*/   
  set_multi_cast(1);
  add_spell("SecondAttack",
    "$HK$Clath$N$'s motions $HC$b l  U   R$N$ as he quickly attacks again.\n",
    "$HK$Clath$N$'s motions $HC$b l  U   R$N$ as he quickly attacks again.\n",
    90, "55-60", "physical", 0);
  add_spell("Bite",
    "\n\t$HK$Clath$N$ lunges at you and $HR$BITES$N$ hard, tearing flesh from the wound!\n\n",  
    "\n\n$HK$Clath$N$ lunges at #CTN# and BITES #TO# hard!\n\n",
    10, "50-100", "physical", 0);     
  add_spell("Scratch",
    "The $HK$Ashdragon$N$ scratches you with a powerful claw.\n",  
    "The $HK$Ashdragon$N$ scratches #CTN# with a powerful claw.\n",
    8, "5-35", "physical", 6);     
  add_spell("AshBloom",
    0,0,
    5, "20-50", "other|poison", 6, "call_blind");                     
}

void call_heal()
{
  if(!present(attacker_ob, environment())) 
    return;
  if(HealNum < 1)
    return;
  HealNum --;
  tell_room(environment(), 
      HIK+"\nWith a billowing W H O O S H, Clath sucks in a lungfull of ash.\n\n"+NORM);
  hit_point += 800+random(600); 
  set_wc(query_wc() + 10 + random(8));
  set_ac(query_ac() + 5 + random(5));
}

/* 
////////////////////////////////////////////////////////////////////////////
//  Function:    call_heal_two
//  Description: heals mob random(50)
//  AC_Bonus:    10
//    .20 (chance) * 49 (avg heal * 2) = 9.8 ==> 10
////////////////////////////////////////////////////////////////////////////
*/
void call_heal_two()
{
  tell_room(environment(),
  "The "+HIK+"Ashdragon"+NORM+" sucks in a breathful of ash.  "+HIK+"Clath"+NORM+" begins to heal.\n");
  heal_self(random(50));
  return;
}

void heart_beat()
{
  ::heart_beat();
  if(attacker_ob) 
  {
    if(!random(5))
      call_heal_two();
  }
  if(HealNum && hit_point <= 400)
    call_heal();
}

/* 
////////////////////////////////////////////////////////////////////////////
//  Function:    call_blind (called from AshBloom spell)
//  Description: hits all attackers for 15-40 other|poison damage and
//               clones a timed object to lower a players WC (simulating
//               blindness from the ash)
//  Arguments:   object target, object room, int damage
//  WC_Bonus:    8 (increased by 200% for limited area attack)
//    .05 (chance) * 34.5 (avg dmg) = 1.725 * 1.5 (dtype) = 2.59 ==> (2.59 * 3) = 7.77 = 8
//  AC_Bonus:    5 (given for a players drop in WC, increased bonus
//                  by 400% because it effects all attackers)
//    .05 (chance) * 24.5 (avg wc drop * avg round) = 1.225 = 1 (2 * 5) ==> 5
////////////////////////////////////////////////////////////////////////////
*/

status check_attacking_me(object ob) 
{
  return (object)ob->query_attack()==this_object();
}


void call_blind(object target, object room, int damage) 
{
  object *nmys;
  object blindob;
  int s,x;
  int time, negwc;
  nmys = filter_array(all_inventory(room), "check_attacking_me", this_object());
  s = sizeof(nmys);
  tell_room(room,"\n"+
    HIK+"Clath"+NORM+" rears back and with a thundering roar fills the air with\n"+
    HIK+".:(:..:):..:(:..:):..:(:..:):..:(:..:):..:(:..:):..:(:..:):..:(:..:):.\n"+NORM);
  tell_room(room,
    HIK+"  .:(:..:):..:(:..:):..:(:.. "+HIW+"CHOKING ASH"+HIK+" ..:):..:(:..:):..:(:..:):..\n"+
    ".:(:..:):..:(:..:):..:(:..:):..:(:..:):..:(:..:):..:(:..:):..:(:..:):.\n\n"+NORM);
  tell_object(target,
    HIK+"You are hit directly in the face by the blast of scalding ash.\n"+NORM);
  tell_room(room,
    (string)target->query_name()+
    " is hit directly in the face by the blast of scalding ash.\n", ({ target }));
  for(x=0; x < s; x++)
  {
	if(nmys[x]->query_interactive()) {
	  nmys[x]->hit_player(15+random(26), "other|poison");
      if(!(present("clath_blind_object", nmys[x]))) 
      {
        tell_object(nmys[x],
          "\n"+HIW+"You are blinded by the cloud of ash."+NORM+"\n\n");
        time = (5 + random(5));
        negwc = (2 + random(4));
        blindob = clone_object(OBJ+"clath_blind_object.c");
        move_object(blindob, nmys[x]);
        blindob->start_blindness(nmys[x], time, negwc);
      }
    }  
  }
}

calculate_worth()
{
  int bonus;

  /* This monsters' main treasure is experience, so players get a bonus instead
    of a badass peice of equipment or armor */
  
  bonus = ::calculate_worth() + 100000;
    
  return bonus;
}

monster_died() 
{  
	object hoard;
#ifdef BIGKILLLOG
  mon_log(BIGKILLLOG);
#endif
   tell_room(environment(this_object()),
    "As "+HIK+"Clath"+NORM+" tumbles to the ground, you notice a pile of\n"+
    "shimmering gold beneath him.\n");
  hoard = clone_object("obj/money");
  hoard->set_money(random(18000)+10000);
  move_object(hoard, environment(this_object()));    
  return 1;
}


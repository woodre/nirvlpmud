#include "/players/maledicta/ansi.h"
inherit "/obj/monster";
/* 
//  ***********************************************************************
//  bonuses, "other|poison" damage in poison attack, "other|evil" damage in 
//  wraith strike attack, poison object cloning added by Forbin 2004.07.26 
//  ***********************************************************************
*/
#define POISON_WC_BONUS 7 /* see function header for calculations */
#define POISONING_WC_BONUS 1 /* see function header for calculations */
#define WRAITH_WC_BONUS 7 /* see function header for calculations */
#define WRAITH_AC_BONUS 6 /* see function header for calculations */
#define HEAL_HP_BONUS 50 /* see function header for calculations */

int heals; 
object fool;

reset(arg) {
   ::reset(arg);
   if (arg) return; 
/*
   move_object(clone_object("/players/maledicta/ares/weapons/daggers.c"), this_object()); 
*/
   move_object(clone_object("/players/forbin/closed/fix/daggers.c"), this_object()); 
   set_short(BOLD+"Direthorne"+NORM);
   set_long(
"  This is a thin man with brown hair and dark eyes. He wears a\n"+
"set of lightweight leather armor and a short shoulder cape. His\n"+
"belt holds a small pouch and a pair of stiletto daggers. You\n"+
"can tell by his confidence and ease that he is a very dangerous\n"+
"man.  You should not attack him if you value your life.\n");
   set_name("direthorne");
   set_alias("DireThorne the Assassin");
   set_race("human");
   set_level(24);
   set_wc(42);
   set_ac(22);
   set_hp(900);
   set_al(-1000);
   set_heart_beat(1);
   heals = random(3) + 3;
   set_wc_bonus(POISON_WC_BONUS + POISONING_WC_BONUS + WRAITH_WC_BONUS); /* Forbin */
   set_ac_bonus(WRAITH_AC_BONUS); /* Forbin */
   set_hp_bonus(HEAL_HP_BONUS * heals); /* Forbin */      
   add_money(3000 + random(1000));   
   set_chance(30);
   set_spell_dam(60 + random(40));
   set_spell_mess1(BOLD+"Direthorne"+NORM+" lashes out with a dagger...\n\n"+
                   HIR+"         -- ----- ---- SLICE ---- ----- --"+NORM+"\n\n"+
                   "                       You are slit open!\n");
   set_spell_mess2("Direthorne slices into his opponent!\n");
   }

heart_beat() {
  object poison; /* added by Forbin */
  ::heart_beat();
  if(attacker_ob) fool = attacker_ob;
  
  if(fool)
  if(present(fool, environment()) && !attacker_ob){
   tell_room(environment(), query_name()+" leaps to the attack!\n");
   attacker_ob = fool;
   }
/* 
//  ***********************************************************************
//  Calculations by Forbin
//  HP_Bonus: 50 * # of starting heals
//    50 (heal mount) * # of heals he starts with (set in reset())
//  ***********************************************************************
*/  
  if(hit_point < 500 && heals){
    tell_room(environment(), 
    query_name()+" grabs a vial from his pouch and drinks it. He is healed!\n");
    hit_point += 50;
    heals -= 1;  
    }
  if(!attacker_ob && random(100) < 5){
    tell_room(environment(), query_name()+" sips an ale while quietly watching the room.\n");
    }  
/* 
//  ***********************************************************************
//  Calculations by Forbin
//  WC_Bonus: 7
//    .10 (chance) * 44 (avg dmg) = 4.4 * 1.5 (no dmg type) = 6.6 = 7
//  ***********************************************************************
*/
  if(attacker_ob && random(100) < 10){ /* "other|poison" by Forbin */
    attacker_ob->hit_player(random(50) + 20, "other|poison"); 
    tell_room(environment(), 
    query_name()+" dashes forward and strikes with his right dagger!\n");
    tell_object(attacker_ob, 
    "You feel a burning pain as Direthorne's dagger slices into you skin...\n"+
    "                   "+GRN+"* P  O  I  S  O  N *"+NORM+"\n"+
    "       You shriek as the agony spreads through your veins!\n");
/*
//  ***********************************************************************
//    poisoning added by Forbin
//    WC_Bonus: 1
//      just put in 1 for the poisoning
//  ***********************************************************************
*/
    if(!present("poison2", attacker_ob)) {
      poison = clone_object("/players/feldegast/obj/poison2.c");
      poison->set_duration(random(3) + 1);
      poison->set_damage(8);    
      move_object(poison, attacker_ob);
    }
/* 
//  ***********************************************************************
//  Calculations by Forbin
//  WC_Bonus: 7
//    .10 (chance) * 44 (avg dmg) = 4.4 * 1.5 (dmg type) = 6.6 = 7
//  AC_Bonus: 6
//    .10 (chance) * 29 (avg heal) = 2.9 * 2 (per rules) = 5.8 = 6
//  ***********************************************************************
*/    
  if(attacker_ob && random(100) < 10){
    attacker_ob->hit_player(random(50) + 20, "other|evil");
    tell_room(environment(), 
    query_name()+" dashes forward and strikes with his left dagger!\n");
    tell_object(attacker_ob, 
    "You begin to feel weak as the left dagger penetrates your skin...\n"+
    "            "+BOLD+"~ W R A "+NORM+HIW+"I T H   S T R"+NORM+BOLD+" I K E ~"+NORM+"\n"+
    "        Undead energy absorbs your life force!\n");
    hit_point += random(30) + 15;
    }
  }
}
/*
//  ***********************************************************************
//    added by Forbin, used to make weapon look wielded 
//  ***********************************************************************
*/

query_direthorne() { return 1; } 

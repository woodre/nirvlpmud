/* Hunter-Seeker
 * It moves randomly around the ChAoS realm, does vicious extra damage, 
 * cannot be peaced, cannot be seen unless looked at, follows players with a
 * memory. Nice xp bonus if killed, however
 */
 
#include "/players/snow/chaos/defs.h"
inherit "/obj/monster.c";
 
#define MEAT this_object()->query_attack()
#define RAN random

string victim;
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
    set_name("hunter-seeker");
    set_short();
    set_race("chaoscreature");
    set_alias("hunter");
    set_long(
"A slim, sharp, floating blade of steel.\n");
    set_level(20);
    set_hp(random(150)+300);
    set_ac(random(8)+12);
    set_wc(random(10)+24);
    set_dead_ob(this_object());
    set_aggressive(1);
    set_chat_chance(10);
    load_chat(
"You hear a buzzing sound...\n");
    load_chat(
"You sense a flicker of motion in the corner of your eye.\n");
    call_out("rebeat",10);
    call_out("hunter_move",random(50));
  }
}
 
monster_died() {
  object party;
  party = present("party object", attacker_ob);
  if(party) party->share_exp(5000);
  if(!party) attacker_ob->add_exp(5000);
  TR(ENV(), "The Hunter-seeker falls to the ground.\n");
  return 0;
}
 
heart_beat() {
  object meat;
  ::heart_beat();
  if(!ENV(TO)) return;
  if(MEAT) {
    if(victim != MEAT->query_real_name()) {
      victim = MEAT->query_real_name(); }
    burrow();
    RE;
  }
  if(!MEAT) {
    if(victim) {
      meat = PRE(victim,ENV(TO));
      if(meat) {
        TO->attack_object(meat);
        burrow();
      RE;
      }
      meat = find_player(victim);
      if(meat) {
        if(ENV(meat)->query_chaos() == "devour") {
          MO(TO,ENV(meat));
          TO->attack_object(meat);
          burrow();
      RE;
        }
      }
    }
    findmeat();
    RE;
  }
  RE;
}
 
findmeat() {
  object ob;
  if(!ENV(TO)) return;
  ob = first_inventory(ENV(TO));
  while(ob) {
    if(ob->is_player()) {
      if(random(10) < 4) {
        TO->attack_object(ob);
        burrow();
        RE;
      }
    }
    ob = next_inventory(ob);
  }
  RE;
}
 
rebeat() { call_out("rebeat",20); set_heart_beat(1); heart_beat(); RE; }
 
hunter_move() {
  int ran;
  string dest;
  if(!ENV(TO)) return;
  call_out("hunter_move",random(50));
  if(MEAT) RE;
  ran = random(9);
  if(ran == 0) dest = C1;
  if(ran == 1) dest = C2;
  if(ran == 2) dest = C3;
  if(ran == 3) dest = C4;
  if(ran == 4) dest = C5;
  if(ran == 5) dest = C6;
  if(ran == 6) dest = C7;
  if(ran == 7) dest = C8;
  if(ran == 8) dest = C9;
  MO(TO,dest);
  RE;
}
 
burrow() {
  if(RAN(10) < 4 || ENV(TO) != ENV(MEAT) ) RE;
  TE(MEAT,"  The Hunter-seeker burrows into your flesh!\n");
  MEAT->add_hit_point(-(RAN(10)+10));
  RE;
}

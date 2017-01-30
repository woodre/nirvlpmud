/* A spiny demon */

inherit "/obj/monster.c";
#include "/players/snow/dark/defs.h"
#define RAN random
#include "/players/snow/closed/cyber/color.h"

string victim;
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
    set_name("spiny demon");
    set_short(BOLD+"Spiny Demon"+OFF);
    set_race("undead");
    set_alias("demon");
    set_long(
"A vicious-looking demon covered with bristling red spines.\n");
    set_level(16);
    set_hp(random(100)+250);
    set_ac(random(12)+7);
    set_wc(random(18)+13);
    set_al(-1000);
    set_dead_ob(this_object());
    set_aggressive(1);
    set_chat_chance(20);
    load_chat(
" The spiny demon glares at you with vicious intent!\n");
    load_chat(
" The spiny demon drools oozing black.\n");
    call_out("monster_move", random(50) + 1);
  }
}
 
monster_died() {
  object party;
  party = present("party object", attacker_ob);
  if(party) party->share_exp(1000);
  if(!party) attacker_ob->add_exp(1000);
  TR(ENV(), "The spiny demon collapses into a puddle of ooze.\n");
  "/players/snow/dark/counter.c"->add_count(-1);
  return 0;
}
 
heart_beat() {
  object meat;
  ::heart_beat();
  if(!environment()) return 1;
  if(attacker_ob) {
    if(victim != attacker_ob->query_real_name()) {
      victim = attacker_ob->query_real_name(); }
    if(ENV(attacker_ob) && ENV(attacker_ob) != ENV(TO) &&
       ENV(attacker_ob)->query_darena() == "boo") MO(TO,ENV(attacker_ob));
    spines();
    RE;
  }
  if(!attacker_ob) {
    if(victim) {
      meat = PRE(victim,ENV(TO));
      if(meat) {
        TO->attack_object(meat);
        spines();
      RE;
      }
      meat = find_player(victim);
      if(meat) {
        if(ENV(meat)->query_darena() == "boo") {
          MO(TO,ENV(meat));
          TO->attack_object(meat);
          spines();
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
  ob = first_inventory(ENV(TO));
  while(ob) {
    if(ob->is_player()) {
      if(random(10) < 4) {
        TO->attack_object(ob);
        spines();
        RE;
      }
    }
    ob = next_inventory(ob);
  }
  RE;
}
 
 
monster_move() {
  int ran;
  string dest;
  call_out("monster_move",random(50));
  if(attacker_ob) RE;
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
 
spines() {
  if(RAN(10) < 4 || ENV(TO) != ENV(attacker_ob) ) RE;
  TE(attacker_ob,
  "  The demon jabs you with its awful spines!\n");
  attacker_ob->add_hit_point(-(RAN(10)+3));
  RE;
}

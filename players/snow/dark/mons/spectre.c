/* A Spectre for the DarK ArenA */

inherit "/obj/monster.c";
#include "/players/snow/dark/defs.h"
#define RAN random
#include "/players/snow/closed/cyber/color.h"

string victim;
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
    set_name("spectre");
    set_short(BOLD+"Spectre"+OFF);
    set_race("undead");
    set_alias("spec");
    set_long(
"A powerful and aggressive spirit. Beware the spectre's wrath!\n");
    set_level(18);
    set_hp(random(150)+250);
    set_ac(random(8)+8);
    set_wc(random(20)+20);
    set_al(-1000);
    set_dead_ob(this_object());
    set_aggressive(1);
    set_chat_chance(15);
    load_chat(
" The spectre laughs hideously!\n");
    load_chat(
" The spectre examines you closely.\n");
    call_out("monster_move", random(50) + 1);
  }
}
 
monster_died() {
  object party;
  party = present("party object", attacker_ob);
  if(party) party->share_exp(2500);
  if(!party) attacker_ob->add_exp(2500);
  TR(ENV(), "The spectre is enveloped in a dark mist and is gone.\n");
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
    drain();
    RE;
  }
  if(!attacker_ob) {
    if(victim) {
      meat = PRE(victim,ENV(TO));
      if(meat) {
        TO->attack_object(meat);
        drain();
      RE;
      }
      meat = find_player(victim);
      if(meat) {
        if(ENV(meat)->query_darena() == "boo") {
          MO(TO,ENV(meat));
          TO->attack_object(meat);
          drain();
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
        drain();
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
 
drain() {
  if(!ENV(TO)) RE;
  if(!attacker_ob) RE;
  if(!ENV(attacker_ob)) RE;
  if(RAN(10) < 4 || ENV(TO) != ENV(attacker_ob) ) RE;
  TE(attacker_ob,"  The spectre drains your energy!\n");
  attacker_ob->heal_self(-(RAN(10)+2));
  attacker_ob->add_exp(-RAN(50));
  RE;
}

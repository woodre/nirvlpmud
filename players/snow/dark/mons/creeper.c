/* A creeping soul for DarK ArenA */
/* added a cpl environment() checks - verte 3-11-01 */

inherit "/obj/monster.c";
#include "/players/snow/dark/defs.h"
#define RAN random
#include "/players/snow/closed/cyber/color.h"

string victim;
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
    set_name("creeping soul");
    set_short("Creeping Soul");
    set_race("undead");
    set_alias("soul");
    set_long(
"A lost soul that has somehow managed to take on some\n\
 physical powers. It looks very unhappy.\n");
    set_level(8);
    set_hp(random(30)+70);
    set_ac(random(3)+3);
    set_wc(random(6)+8);
    set_al(-1000);
    set_dead_ob(this_object());
    set_aggressive(1);
    set_chat_chance(15);
    load_chat(
" The lost soul creeps along...\n");
    load_chat(
" The lost soul looks at you with hate-filled eyes.\n");
    call_out("monster_move", random(50) + 1);
  }
}
 
monster_died() {
  object party;
  party = present("party object", attacker_ob);
  if(party) party->share_exp(200);
  if(!party) attacker_ob->add_exp(200);
  TR(ENV(), "The lost soul cries out in happy release!\n");
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
    grab();
    RE;
  }
  if(!attacker_ob) {
    if(victim) {
      meat = PRE(victim,ENV(TO));
      if(meat) {
        TO->attack_object(meat);
        grab();
      RE;
      }
      meat = find_player(victim);
      if(meat) {
        if(ENV(meat)->query_darena() == "boo") {
          MO(TO,ENV(meat));
          TO->attack_object(meat);
          grab();
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
        grab();
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
 
grab() {
  if(!environment() || !attacker_ob || !environment(attacker_ob)) return;
  if(RAN(10) < 4 || ENV(TO) != ENV(attacker_ob) ) RE;
  TE(attacker_ob,"  The Creeping Soul grabs onto you!\n");
  attacker_ob->add_hit_point(-(RAN(5)+1));
  RE;
}

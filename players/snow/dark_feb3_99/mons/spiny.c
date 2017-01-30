/* A spiny demon */

inherit "/obj/monster.c";
#include "/players/snow/dark/defs.h"
#define MEAT this_object()->query_attack()
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
    call_out("rebeat",50);
    call_out("monster_move",random(50));
  }
}
 
monster_died() {
  TR(ENV(TO),
    "The spiny demon collapses into a puddle of ooze.\n");
  MEAT->add_exp(500);
  "/players/snow/dark/counter.c"->add_count(-1);
  return 0;
}
 
heart_beat() {
  object meat;
  ::heart_beat();
  if(MEAT) {
    if(victim != MEAT->query_real_name()) {
      victim = MEAT->query_real_name(); }
    if(ENV(MEAT) && ENV(MEAT) != ENV(TO) &&
       ENV(MEAT)->query_darena() == "boo") MO(TO,ENV(MEAT));
    spines();
    RE;
  }
  if(!MEAT) {
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
 
rebeat() { call_out("rebeat",50); set_heart_beat(1); heart_beat(); RE; }
 
monster_move() {
  int ran;
  string dest;
  call_out("monster_move",random(50));
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
 
spines() {
  if(RAN(10) < 4 || ENV(TO) != ENV(MEAT) ) RE;
  TE(MEAT,
  "  The demon jabs you with its awful spines!\n");
  MEAT->add_hit_point(-(RAN(10)+3));
  RE;
}

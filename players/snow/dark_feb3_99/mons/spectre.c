/* A Spectre for the DarK ArenA */

inherit "/obj/monster.c";
#include "/players/snow/dark/defs.h"
#define MEAT this_object()->query_attack()
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
    call_out("rebeat",50);
    call_out("monster_move",random(50));
  }
}
 
monster_died() {
  TR(ENV(TO),
    "The spectre is enveloped in a dark mist and is gone.\n");
  MEAT->add_exp(1500);
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
    drain();
    RE;
  }
  if(!MEAT) {
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
 
drain() {
  if(RAN(10) < 4 || ENV(TO) != ENV(MEAT) ) RE;
  TE(MEAT,"  The spectre drains your energy!\n");
  MEAT->heal_self(-(RAN(10)+2));
  MEAT->add_exp(-RAN(50));
  RE;
}

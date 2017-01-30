/* A monster */

inherit "/obj/monster.c";
#include "/players/snow/dark/defs.h"
#define MEAT this_object()->query_attack()
#define RAN random
#include "/players/snow/closed/cyber/color.h"

string victim;
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
    set_name("skeleton");
    set_short(BOLD+"Skeleton"+OFF);
    set_race("undead");
    set_alias("skel");
    set_long(
"An animated bundle of bones.\n");
    set_level(5);
    set_hp(random(30)+60);
    set_ac(random(5)+4);
    set_wc(random(8)+8);
    set_al(-1000);
    money = random(50);
    set_dead_ob(this_object());
    set_aggressive(1);
    set_chat_chance(20);
    load_chat(
" The skeleton rattles around...\n");
    load_chat(
" The skeleton advances toward you...\n");
    call_out("rebeat",50);
    call_out("monster_move",random(50));
  }
}
 
monster_died() {
  TR(ENV(TO),
    "The skeleton collapses into a heap of bones.\n");
  MEAT->add_exp(50);
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
  RE;
  }
  if(!MEAT) {
    if(victim) {
      meat = PRE(victim,ENV(TO));
      if(meat) {
        TO->attack_object(meat);
      RE;
      }
      meat = find_player(victim);
      if(meat) {
        if(ENV(meat)->query_darena() == "boo") {
          MO(TO,ENV(meat));
          TO->attack_object(meat);
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
RE;
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

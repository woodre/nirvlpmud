/* A zombie for DarK ArenA */

inherit "/obj/monster.c";
#include "/players/snow/dark/defs.h"
#define MEAT this_object()->query_attack()
#define RAN random
#include "/players/snow/closed/cyber/color.h"

string victim;
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
    set_name("zombie");
    set_short(BOLD+"Zombie"+OFF);
    set_race("undead");
    set_alias("zomb");
    set_long(
"A shambling mound of rotting flesh in vaguely human form.\n");
    set_level(10);
    set_hp(random(100)+100);
    set_ac(random(4)+4);
    set_wc(random(8)+12);
    set_al(-1000);
    set_dead_ob(this_object());
    set_aggressive(1);
    set_chat_chance(20);
    load_chat(
" The zombie creates a ferocious stink!\n");
    load_chat(
" The zombie groans sickeningly.\n");
    call_out("rebeat",50);
    call_out("monster_move",random(50));
  }
}
 
monster_died() {
  TR(ENV(TO),
    "The zombie collapses into rotting flesh.\n");
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
    pound();
    RE;
  }
  if(!MEAT) {
    if(victim) {
      meat = PRE(victim,ENV(TO));
      if(meat) {
        TO->attack_object(meat);
        pound();
      RE;
      }
      meat = find_player(victim);
      if(meat) {
        if(ENV(meat)->query_darena() == "boo") {
          MO(TO,ENV(meat));
          TO->attack_object(meat);
          pound();
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
        pound();
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
 
pound() {
  if(RAN(10) < 4 || ENV(TO) != ENV(MEAT) ) RE;
  TE(MEAT,
     "  The zombie pounds you with fists of rotting flesh!\n");
  MEAT->add_hit_point(-(RAN(10)+3));
  RE;
}

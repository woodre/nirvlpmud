/* A shadow - undead creature in DarK ArenA */

inherit "/obj/monster.c";
#include "/players/snow/dark/defs.h"
#define MEAT this_object()->query_attack()
#define RAN random
#include "/players/snow/closed/cyber/color.h"

string victim;
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
    set_name("shadow");
    set_short(BOLD+"Shadow"+OFF);
    set_race("undead");
    set_alias("shad");
    set_long(
"   This poor wandering soul lives a dark and gloomy life.\n\
 It is an insubstantial and brittle wisp but can inflict\n\
 great damage.\n");
    set_level(14);
    set_hp(random(50)+200);
    set_ac(random(5)+5);
    set_wc(random(10)+15);
    money = random(600);
    set_dead_ob(this_object());
    set_aggressive(0);
    set_chat_chance(5);
    load_chat(
" The shadow whispers: oh woe is me...\n");
    load_chat(
" The shadow glides slowly about you...\n");
    call_out("rebeat",50);
    call_out("monster_move",random(50));
  }
}
 
monster_died() {
  TR(ENV(TO),
    "  The shadow collapses in on itself!\n");
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
    shadow_touch();
    RE;
  }
  if(!MEAT) {
    if(victim) {
      meat = PRE(victim,ENV(TO));
      if(meat) {
        TO->attack_object(meat);
        shadow_touch();
      RE;
      }
      meat = find_player(victim);
      if(meat) {
        if(ENV(meat)->query_darena() == "boo") {
          MO(TO,ENV(meat));
          TO->attack_object(meat);
          shadow_touch();
      RE;
        }
      }
    }
    RE;
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
 
shadow_touch() {
  if(RAN(10) < 4 || ENV(TO) != ENV(MEAT) ) RE;
  TE(MEAT,
  "  The Shadow's touch sends a deathly chill down your spine!\n");
  MEAT->add_hit_point(-(RAN(10)+2));
  RE;
}

/* A shadow - undead creature in DarK ArenA */

inherit "/obj/monster.c";
#include "/players/snow/dark/defs.h"
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
  }
}
 
monster_died() {
  object party;
  party = present("party object", attacker_ob);
  if(party) party->share_exp(500);
  if(!party) attacker_ob->add_exp(500);
  TR(ENV(), "  The shadow collapses in on itself!\n");
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
    shadow_touch();
    RE;
  }
  if(!attacker_ob) {
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
 
 
 
shadow_touch() {
  if(RAN(10) < 4 || ENV(TO) != ENV(attacker_ob) ) RE;
  TE(attacker_ob,
  "  The Shadow's touch sends a deathly chill down your spine!\n");
  attacker_ob->add_hit_point(-(RAN(10)+2));
  RE;
}

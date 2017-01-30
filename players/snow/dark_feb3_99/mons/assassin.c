/* An Undead Assassin for DarK ArenA */

inherit "/obj/monster.c";
#include "/players/snow/dark/defs.h"
#define MEAT this_object()->query_attack()
#define RAN random
#include "/players/snow/closed/cyber/color.h"

string victim;
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
    set_name("assassin");
    set_short(BOLD+"Undead Assassin"+OFF);
    set_race("undead");
    set_alias("assa");
    set_long(
"This used to be an evil human. Now it is something far\n\
 more deadly. This undead assassin will hunt you down\n\
 and kill you without the slightest remorse or fear.\n");
    set_level(20);
    set_hp(random(200)+300);
    set_ac(random(6)+14);
    set_wc(random(20)+25);
    set_al(-1000);
    money = random(3000)+2000;
    set_dead_ob(this_object());
    set_aggressive(1);
    set_chat_chance(20);
    load_chat(
" The assassin grins evilly.\n");
    load_chat(
" The assassin licks its lips.\n");
    call_out("monster_move",random(50));
  }
}
 
monster_died() {
  TR(ENV(TO),
    "The undead assassin wails in terror and is sucked away!\n");
  MEAT->add_exp(1000);
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
    backstab();
    RE;
  }
  if(!MEAT) {
    if(victim) {
      meat = PRE(victim,ENV(TO));
      if(meat) {
        TO->attack_object(meat);
      backstab();
      RE;
      }
      meat = find_player(victim);
      if(meat) {
        if(ENV(meat)->query_darena() == "boo") {
          MO(TO,ENV(meat));
          TO->attack_object(meat);
          backstab();
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
        backstab();
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
  if(!TO || TO->query_hp() < 20) RE;
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
 
backstab() {
  if(RAN(10) < 4 || ENV(TO) != ENV(MEAT) ) RE;
  TE(MEAT,"  The undead assassin stabs you in the back!\n");
  MEAT->add_hit_point(-(RAN(10)+10));
  RE;
}

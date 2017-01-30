/* Quickling */
 
inherit "/obj/monster.c";
#include "/players/snow/chaos/defs.h"
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
    set_name("quickling");
    set_race("chaoscreature");
    set_alias("sprite");
    set_short();
    set_long(
"This is a short, thin, sprite-like creature. It moves at an incredible\n"+
"speed so that you can barely follow its blur...\n");
    set_level(18);
    set_hp(random(100)+100);
    set_ac(random(8)+25);
    set_wc(random(10)+10);
    set_dead_ob(this_object());
    set_aggressive(1);
     if(!random(3)) set_whimpy();
    set_chat_chance(20);
    set_a_chat_chance(10);
    load_chat(
"ZZZZZzzzzzzzzzzzzip!\n");
    load_chat(
"You hear the pitter-patter of little feet...\n");
    load_a_chat("ZZZZZzzzzzzzzzzzzip!\n");
    load_a_chat("The Quickling moves in a blur around you!\n");
    money = random(1000)+750;
    call_out("quick_move",random(20)+10);
  }
}
 
monster_died() {
  TR(ENV(TO),
    "The Quickling's legs spin rapidly, kick once, twice, then are still.\n");
  return 0;
}
 
heart_beat() {
  object meat;
  int i;
  ::heart_beat();
  if(attacker_ob) {
    for(i=0; i<random(8); i++) {
      already_fight = 0; attack(); } }
  findmeat();
  if(!attacker_ob) findmeat();
}
 
findmeat() {
  object ob;
  if(!environment()) return 1;
  ob = first_inventory(environment(this_object()));
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
 
 
quick_move() {
  int ran;
  string dest;
  call_out("quick_move",random(50));
  if(attacker_ob && random(10) < 7) RE;
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

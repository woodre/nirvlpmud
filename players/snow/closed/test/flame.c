/*
 * Flame, second challenge in the test
 [5.25.01] Vertebraker changed dmg to other|fire
 */
 
#include "defs.h"
inherit "/obj/monster.c";
#include "/players/snow/closed/color.h"

object testvic;
 
#define MEAT this_object()->query_attack()
#define RAN random

string victim;
int totdam, changed;
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
    set_name("flame");
    set_short(RED+"Flame"+OFF);
    set_race("second");
    set_alias("flam");
    set_long(
"\tYou look upon Flame, second challenge in your test.\n"+
"Flame is a flickering being whose substance seems to be of white-\n"+
"hot fire. Its motions are random but menacing.\n");
    set_level(20);
     set_hp(600);
     set_ac(25);
     set_wc(60);
    set_dead_ob(this_object());
    set_aggressive(1);
    set_chat_chance(10);
  }
}
 
monster_died() {
  object wave;
  wave = clone_object("/players/snow/closed/test/wave.c");
  TR(ENV(TO),
    "\n\tThe last of Flame's fires flickers and fades away.\n\n"+
    "\tYou have completed the second test of might!\n\n"+
    "\tWater seeps into the room and forms Wave!\n\n");
    move_object(wave,TO);
  wave->attack_object(testvic);
  wave->set_testvic(testvic);
    extra_xp(attacker_ob);
    logMyDeath();
  return 0;
}
 
heart_beat() {
  object meat;
  ::heart_beat();
  find_victim();
  check_self();
  if(MEAT && totdam < 21) strike();
  if(!changed && totdam > 19) change();
  if(!changed) TO->heal_self(200);
  return;
}
 
change() {
  TR(ENV(TO), "The outer fires protecting Flame die down!\n");
/* added 5 to each of these, he was too too easy after flames 
  died out. - Jaraxle [7/18/03] */
  TO->set_ac(15);
  TO->set_wc(40);
  changed = 1;
  RE; }
 
rebeat() { call_out("rebeat",20); set_heart_beat(1); heart_beat(); RE; }
 
strike() {
  TR(ENV(TO),"\n\tFlame calls "+RED+"FIRE"+OFF+" from the heavens!\n");
/* added R16 to this. - Jaraxle [7/18/03] */
/* removed 5 from this (after random count change)
   - Jaraxle [9/6/03] */
if(MEAT) MEAT->hit_player(random(16)+35, "other|fire");
/* Changed this to give a little randomness to how long
   the spell casting will last.  Beefed up nice.
   - Jaraxle [9/6/03] */
switch(random(3)){
  case 0..1: totdam++;
break;
case 2: return;
break;
}
  RE;
}

#include "defenses.h"
#include "logme.h"


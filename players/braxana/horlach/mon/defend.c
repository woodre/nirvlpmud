#include "/players/mythos/closed/guild/def.h"
inherit "players/mythos/closed/guild/spells/monster2";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("scorpion");
  set_alias("monster");
  set_race("creature");
  set_short("Giant Scorpion");
  set_long("A giant scorpion- a nightmare come to life.\n"+
           "A black outer shell and white tail- tipped with \n"+
           "a glowing spike.  You might want to run.\n");
  set_level(30);
  set_hp(500);
  set_aggressive(1);
  set_al(-1000);
  set_wc(50);
  set_ac(18);
  set_heal(5,10);
  set_a_chat_chance(10);
  load_a_chat("A scorpion lashes out!\n");
  load_a_chat("A Scorpion strikes with blinding speed!\n"); 
  set_chance(20);
  set_spell_dam(50);
  set_spell_mess1("A scorpion lashes out!\n");
  set_spell_mess2("A long nasty spiked tail lashes out and you are in agony!\n"); 
  if(random(2)==0) {
     set_mult(random(5) + 2);
     set_mult_chance(40);
     set_mult_dam1(5);
     set_mult_dam2(10); }
}


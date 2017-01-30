#include "/players/mythos/closed/ansi.h"
inherit "obj/monster";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("tochau");
  set_race("yokai");
  set_short("A Yokai: Tochau");
  set_long("This is an ugly looking creature.  It looks like a large crab\n"+
    "with a large long claw-like tail.  It is a creature\n"+
    "of great speed and ferocity.\n");
  set_hp(475);
  set_level(19);
  set_al(0);
  set_wc(28);
  set_ac(16);
  set_aggressive(1);
  set_a_chat_chance(15);
  load_a_chat("Tochau lunges forward..its claw-like tail gleams in the light...\n");
  load_a_chat("The ground is ripped apart as Tochau attacks you.\n");
  set_chance(50);
  set_spell_dam(20);
  set_spell_mess1("Tochau lunges toward "+"its enemy"+"!\n"+
  "You hear a great SLASH and blood is everywhere!\n");
  set_spell_mess2("Tochau moves toward you..."+
  "IT is a "+CYN+"bbbbbbllllllluuuurrrrr...\n"+NORM+
  "Suddenly you feel something sharp slash through you.....\n"+
  "Your blood is everywhere!\n");
  call_out("stun",5);
}

stun() {
  if(this_object()->query_hp() < 100) {
  object ob;
  tell_room(environment(this_object()),
  "Tochau falls over- it is stunned.\n");
  ob = clone_object("/players/mythos/amisc/stun.c");
  move_object(ob,environment(this_object()));
  destruct(this_object());
  return 1; }
  call_out("stun",5);
return 1;
}

/* Created <5/12/00> by Jara */

inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

  add_money(600);
  set_name("worker");
  set_short("A warehouse worker");
  set_race("human");
  set_long("The worker is a middle-aged man with dark hair and a beard. His\n"+
   "overalls are worn at the knees and he wears a pair of muddied\n"+
    "workboots.\n");
  set_level(12);
  set_ac(9);
  set_wc(16);
  set_hp(180);
  set_al(0);
  set_aggressive(0);
  set_chat_chance(15);
  set_a_chat_chance(10);
  load_chat("The worker moves one of the heavy crates.\n");
  load_chat("The worker nods at you.\n");
  load_a_chat("The worker slugs you with his fist.\n");
  call_out("random_move",20+random(20));
   }
}

random_move() {
  if(!attacker_ob)
  ::random_move();
  call_out("random_move",6+random(10));
}

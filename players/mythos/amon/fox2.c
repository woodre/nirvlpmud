inherit "obj/monster";
reset(arg)  {
  object gold;
  ::reset(arg);
  if(arg) return;
  set_name("fox");
  set_race("spirit");
  set_short("A small quick fox");
  set_long("A small viscious looking fox who snaps\n"+
      "at you when you draw near.  Its bad mood\n"+
      "might be cured if you 'kiss'ed it.\n");
  set_level(3);
  set_hp(45);
  set_al(-100);
  set_wc(7);
  set_ac(4);
  set_aggressive(0);
  set_chat_chance(10);
  set_frog();
  set_a_chat_chance(15);
  load_chat("The fox laughs at you.\n");
  load_chat("The fox runs circles around you.\n");
  load_a_chat("The fox glowers at you and strikes quickly.\n");
  load_a_chat("The fox laughs at you.\n");
  gold = clone_object("obj/money");
  gold->set_money(random(30)+70);
  move_object(gold,this_object());
}

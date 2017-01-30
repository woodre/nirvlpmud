inherit "obj/monster";

reset(arg)  {
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
  set_name("slayer");
  set_race("avatar");
  set_alias("slayer");
  set_short("The Slayer");
  set_long("It is he- The Slayer.  HE radiates heat\n"+
    "that seems to melt everything around him. Take Care.\n");
  set_level(20);
  set_hp(1000);
  set_al(1000);
  set_wc(30);
  set_ac(4);
  set_aggressive(0);
  set_chat_chance(50);
  set_a_chat_chance(30);
  load_chat("The heat seems to drain your strength.\n");
  load_chat("The Slayer seems to grin.\n");
  load_a_chat("The Slayer says: None shall LEAVE!\n");
  load_a_chat("The Heat saps you strength.\n");
  gold = clone_object("obj/money");
  gold->set_money(random(1000)+2000);
  move_object(gold,this_object());
  weapon = clone_object("/players/mythos/prac/sunb.c");
  move_object(weapon,this_object());
  init_command("wield sword");
  armor = clone_object("/players/mythos/prac/suna.c");
  move_object(armor,this_object());
}

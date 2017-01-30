inherit "obj/monster";

reset(arg)  {
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
  set_name("man");
  set_race("human");
  set_alias("man");
  set_short("A nasty looking man");
  set_long("A nasty looking man.  WATCH OUT!\n");
  set_level(6);
  set_hp(1000);
  set_al(-1000);
  set_wc(18);
  set_ac(2);
  set_aggressive(0);
  set_chat_chance(30);
  set_a_chat_chance(10);
  load_chat("A whisper is in the wind...HE WIELDS DOOM\n");
  load_chat("Man says: Ready to Die?\n");
  load_a_chat("Man says: Be Gone!  Or I Shall Nail Your Hide To The Wall!\n");
  load_a_chat("He Who Wields Soul Blade smashes you against the wall!\n");
  gold = clone_object("obj/money");
  gold->set_money(random(5)+5);
  move_object(gold,this_object());
  weapon = clone_object("/players/mythos/prac/swp.c");
  move_object(weapon,this_object());
  armor = clone_object("/players/mythos/prac/simparm.c");
  move_object(armor,this_object());
}

init() {
  ::init();
  add_action("heal_self","heal_self");
}

heal_self() {
    say("hahahhahaha\n");
  return 1;}

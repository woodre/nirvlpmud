inherit "obj/monster";
reset(arg) {
  object weapon,treasure;
  ::reset(arg);
  if(arg) return;
  set_name("hugo the annoying");
  set_race("hugo");
  set_alias("hugo");
  set_short("Hugo the highly annoying");
  set_long("This fellow is what his title states. He is annoying.\n"+
	"Not only that, but he smells pretty bad, like something that\n"+
	"you stepped on yesterday.\n");
  set_level(10);
  set_hp(150);
  set_al(0);
  set_ac(8);
  set_wc(14);
  set_chance(25);
  set_spell_dam(12);
  set_spell_mess1("Hugo stomps you in the head!");
  set_spell_mess2("Hugo screams: Leave me alone!");
  set_chat_chance(11);
  load_chat("Hugo pokes you in the ribs.\n");
  load_chat("Hugo kicks you.  OUCH!!\n");
  load_chat("Hugo licks you.\n");
weapon=clone_object("players/mizan/etheriel/heals/spam.c");
move_object(weapon, this_object());
treasure=clone_object("obj/money");
treasure->set_money(100+random(100));
move_object(treasure, this_object());
	}

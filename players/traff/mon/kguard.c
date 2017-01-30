inherit "obj/monster";

reset(arg)
{
  object coins,weapon;
  ::reset(arg);
  if(arg) return;
set_name("guard");
set_race("human");
set_alias("man");
set_short("Guard");
set_long("A guard standing watch in front of the keep.\n");
set_level(15);
set_hp(225);
set_al(-250);
set_wc(20);
set_ac(12);
  set_chat_chance(2);
  set_a_chat_chance(10);
load_chat("Guard says: Best move along now, it's getting late.\n");
load_chat("Guard says: I wouldn't stay too long, strangers often disappear around here!\n");
load_chat("Guard says: The arena is always looking for good fighters of any level\n");
load_chat("Guard says: If you go to the tavern, tell Jill to save a mug for me.\n");
load_chat("Guard says: Odd things happen in the keep these days.  I'm glad I'm out here.\n");
load_a_chat("Guard shouts: As long as I live, you shall not enter.\n");
load_a_chat("Guard shouts: Only deaths awaits you in there.\n");
load_a_chat("Guard shouts: GUARDS! To me!  Intruders at the keep!\n");
  coins=clone_object("obj/money");
  coins->set_money(random(101)+750);
  move_object(coins,this_object());
  weapon = clone_object("/players/traff/weps/sword.c");
  move_object(weapon,this_object());
  init_command("wield sword");
}

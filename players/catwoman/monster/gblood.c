inherit "obj/monster.talk";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name(" a shadow");
set_long("not much to see here.\n");
set_al(-100);
set_race("human");
set_level(11);
set_wc(15);
set_hp(400);
set_ac(12);
  set_spell_mess1("hits you bad\n");
set_spell_mess2("hits you again\n");
set_chance(15);
set_spell_dam(15);
set_aggressive(1);
coins = clone_object("obj/money");
coins->set_money(400 + random(150));
move_object(coins,this_object());
}


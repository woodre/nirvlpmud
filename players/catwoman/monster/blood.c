inherit "obj/monster.talk";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("blood");
set_short("A Blood");
set_long("This kid thinks he's tough.\n");
set_al(-100);
set_race("human");
set_level(9);
set_wc(15);
set_hp(200 + random(135));
set_ac(12);
set_spell_mess1("Blood hits a hard blow!\n");
set_spell_mess2("Blood hits you hard\n");
set_chance(15);
set_spell_dam(25);
set_aggressive(0);
coins = clone_object("obj/money");
coins->set_money(350 + random(100));
move_object(coins,this_object());
}


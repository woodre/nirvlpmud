inherit "obj/monster.talk";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("spiderman");
set_short("Spiderman");
set_long("This looks like hes dressed for halloween.\n");
set_al(0);
set_race("human");
set_level(13);
set_wc(18);
set_hp(390);
set_ac(9);
set_spell_mess1("Spidy hits you with webbing\n");
set_spell_mess2("Spidy kicks you in the head\n");
set_chance(15);
set_spell_dam(23);
set_aggressive(0);
coins = clone_object("obj/money");
coins->set_money(500 + random(200));
move_object(coins,this_object());
}


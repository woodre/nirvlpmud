inherit "obj/monster.talk";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("batman");
set_short("Batman");
set_long("This is the legendary Batman.\n");
set_al(1000);
set_race("human");
set_level(8);
set_wc(12);
set_hp(120);
set_ac(7);
set_spell_mess1("Batman kicks dirt in your eyes\n");
set_spell_mess2("Batman trips you\n");
set_chance(15);
set_spell_dam(5);
set_aggressive(0);
coins = clone_object("obj/money");
coins->set_money(350);
move_object(coins,this_object());
}


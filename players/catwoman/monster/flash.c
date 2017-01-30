inherit "obj/monster.talk";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("flash");
set_short("The Flash");
set_long("He looks pretty fast.\n");
set_al(0);
set_race("human");
set_level(17);
set_wc(24);
set_hp(425);
set_ac(18);
set_spell_mess1("The Flash hits you again\n");
set_spell_mess2("The Flash hits you again\n");
set_chance(15);
set_spell_dam(15);
set_aggressive(0);
coins = clone_object("obj/money");
coins->set_money(300+(random(700)));
move_object(coins,this_object());
}

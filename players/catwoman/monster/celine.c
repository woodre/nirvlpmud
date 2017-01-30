inherit "obj/monster.talk";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("celine");
set_short("Celine The goddess(cat like)");
set_long("It would be a shame to cover this body in clothes(however).\n");
set_al(-1000);
set_race("human");
set_level(10);
set_wc(18);
set_hp(150);
set_ac(8);
set_spell_mess1("Celine throws her head back and cackles with glee\n");
set_spell_mess2("Celine hits you again\n");
set_chance(17);
set_spell_dam(10);
set_aggressive(0);
coins = clone_object("obj/money");
coins->set_money(250+(random(200)));
move_object(coins,this_object());
}

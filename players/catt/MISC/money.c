
inherit"obj/monster";
reset(arg) {
object money;
::reset(arg);
if(arg) return;
set_name("moneymaker");
set_alias("money");
set_short("moneymaker");
set_long(
"kill it , it makes money\n");
set_level(1);
set_race("human");
set_hp(10);
set_wc(1);
set_ac(1);
set_spell_mess2("");
money = clone_object("obj/money");
money->set_money(200000);
move_object(money, this_object());
}

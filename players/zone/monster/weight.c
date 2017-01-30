
inherit"obj/monster";
reset(arg) {
object money;
::reset(arg);
if(arg) return;
set_name("weight");
set_alias("weight");
set_short("Weight");
set_long(
"An undead beastie\n");
set_level(19);
set_race("undead");
set_hp(475);
set_wc(30);
set_ac(17);
set_chance(50);
set_spell_dam(30);
set_spell_mess1("The weight uses a word of power!");
money = clone_object("obj/money");
money->set_money(1000);
move_object(money, this_object());
}

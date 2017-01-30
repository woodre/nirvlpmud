
inherit"obj/monster";
reset(arg) {
object money;
::reset(arg);
if(arg) return;
set_name("banshee");
set_alias("banshee");
set_short("Banshee");
set_long(
"An immaterial creature filled with hate.  It's voice is supposed\n" +
"to be death.\n");
set_level(15);
set_race("undead");
set_hp(250);
set_wc(20);
set_ac(12);
set_chance(10);
set_spell_dam(50);
set_spell_mess1("The banshee wails with anger.");
money = clone_object("obj/money");
money->set_money(500);
move_object(money, this_object());
}

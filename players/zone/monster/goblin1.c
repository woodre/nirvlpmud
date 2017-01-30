
inherit"obj/monster";
reset(arg) {
object money;
object armor;
::reset(arg);
if(arg) return;
set_name("goblin");
set_alias("goblin");
set_short("Goblin");
set_long(
"An ugly green creature with lots 'o warts all over.\n");
set_level(7);
set_race("monster");
set_hp(70);
set_wc(12);
set_ac(5);
money = clone_object("obj/money");
money->set_money(124);
move_object(money, this_object());
armor = clone_object("/players/zone/obj/shield.c");
if(armor) {
move_object(armor,this_object());
   }
}

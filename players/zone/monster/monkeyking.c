
inherit"obj/monster";
reset(arg) {
object money;
object weapon;
::reset(arg);
if(arg) return;
set_name("monkey");
set_alias("king");
set_short("Monkey King");
set_long(
"A large albino stone monkey toting a long heavy pole.\n");
set_level(30);
set_race("monkey");
set_hp(1750);
set_wc(50);
set_ac(25);
money = clone_object("obj/money");
money->set_money(1500);
move_object(money, this_object());
weapon = clone_object("/players/zone/obj/pole.c");
if(weapon) {
move_object(weapon,this_object());
   }
}

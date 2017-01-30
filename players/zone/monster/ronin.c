
inherit"obj/monster";
reset(arg) {
object money;
object weapon;
::reset(arg);
if(arg) return;
set_name("ronin");
set_alias("ronin");
set_short("Ronin");
set_long(
"A samuri warrior that was released from service and holds no alligence.\n");
set_level(25);
set_race("man");
set_hp(600);
set_wc(50);
set_ac(23);
money = clone_object("obj/money");
money->set_money(200);
move_object(money, this_object());
weapon = clone_object("/players/zone/obj/katana.c");
if(weapon) {
move_object(weapon,this_object());
}
}

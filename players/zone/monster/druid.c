
inherit"obj/monster";
reset(arg) {
object money;
object weapon;
::reset(arg);
if(arg) return;
set_name("druid");
set_alias("druid");
set_short("Druid");
set_long(
"A robed nature worshiper.  Suspected of errecting menheirs and dolamens\n";+
"all over the european and mideastern area.\n");
set_level(14);
set_race("man");
set_hp(350);
set_wc(20);
set_ac(14);
money = clone_object("obj/money");
money->set_money(200);
move_object(money, this_object());
weapon = clone_object("/players/zone/obj/sickle.c");
if(weapon) {
move_object(weapon,this_object());
}
}

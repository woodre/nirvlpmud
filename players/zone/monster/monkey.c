
inherit"obj/monster";
reset(arg) {
object money;
::reset(arg);
if(arg) return;
set_name("monkey");
set_alias("monkey");
set_short("Monkey");
set_long(
"A playfull monkey with short orange hair and large wet black eyes.\n");
set_level(20);
set_race("monkey");
set_hp(500);
set_wc(30);
set_aggressive(1);
set_ac(17);
money = clone_object("obj/money");
money->set_money(200);
move_object(money, this_object());
}

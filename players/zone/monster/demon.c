
inherit"obj/monster";
reset(arg) {
object money;
::reset(arg);
if(arg) return;
set_name("demon");
set_alias("demon");
set_short("Demon");
set_long(
"A distorted blotchy face with unnaturally smooth skin.\n");
set_level(19);
set_race("monster");
set_hp(475);
set_wc(30);
set_ac(19);
money = clone_object("obj/money");
money->set_money(1000);
move_object(money, this_object());
}

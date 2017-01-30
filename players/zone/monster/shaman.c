
inherit"obj/monster";
reset(arg) {
object money;
::reset(arg);
if(arg) return;
set_name("shaman");
set_alias("shaman");
set_short("Shaman");
set_long(
"An old shaman.  His totem is the Coyote.  He appears to be meditating.\n");
set_level(18);
set_race("man");
set_hp(450);
set_wc(28);
set_ac(15);
money = clone_object("obj/money");
money->set_money(500);
move_object(money, this_object());
}

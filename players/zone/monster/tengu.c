
inherit"obj/monster";
reset(arg) {
object money;
::reset(arg);
if(arg) return;
set_name("tengu");
set_alias("tengu");
set_short("tengu");
set_long(
"An eastern demon.\n");
set_level(20);
set_race("demon");
set_hp(1000);
set_wc(30);
set_ac(17);
money = clone_object("obj/money");
money->set_money(1242);
move_object(money, this_object());
  }

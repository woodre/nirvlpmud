inherit "obj/monster";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("ghoul");
set_short("Moat Ghoul");
set_long("As you stare at the ghoul all you see is DEATH!\n");
set_level(20);
set_wc(30);
set_ac(17);
set_hp(250);
set_aggressive(1);
coins = clone_object("obj/money");
coins->set_money(20+(random(10)));
move_object(coins,this_object());
}

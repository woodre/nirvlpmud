inherit "obj/monster.talk";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("rat");
set_short("A giant rat");
set_long("It runs away.\n");
set_al(-50);
set_level(9);
set_wc(11);
set_hp(190);
set_ac(4);
set_aggressive(1);
coins = clone_object("obj/money");
coins->set_money(100+(random(100)));
move_object(coins,this_object());
}


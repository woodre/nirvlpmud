inherit "obj/monster.talk";
object coins, item;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("mario");
set_short("Mario");
set_long("Yup, you guessed it; the little dude from the arcade game got loose.\n");
set_al(150);
set_level(10);
set_wc(8);
set_hp(125);
set_ac(6);
set_aggressive(0);

item = clone_object("players/grimm/weapons/plunger");
move_object(item,this_object());
coins = clone_object("obj/money");
coins->set_money(100+(random(200)));
move_object(coins,this_object());
}

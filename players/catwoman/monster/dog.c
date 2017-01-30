inherit "obj/monster.talk";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("dog");
set_short("guard dog");
set_long("Yep its a dog.\n");
set_al(-20);
set_level(5);
set_wc(9);
set_hp(90);
set_ac(5);
set_aggressive(0);
coins = clone_object("obj/money");
coins->set_money(125+(random(100)));
move_object(coins,this_object());
}


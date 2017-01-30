inherit "obj/monster.talk";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("zombie");
set_short("Cavern Zombie");
set_long("This is a mindless zombie that dwells in the caverns.\n");
set_level(17);
set_al(-100);
set_wc(20);
set_ac(13);
set_hp(400);
set_aggressive(1);
set_chat_chance(10);
load_chat("Zombie chants: Kill...Kill...Kill...\n");
coins = clone_object("obj/money");
coins->set_money(456+(random(100)));
move_object(coins,this_object());
}

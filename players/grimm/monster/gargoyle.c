inherit "obj/monster.talk";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("gargoyle");
set_short("Guardian Gargoyle");
set_long("This is the gaurdian of the cloak of Malichi.\n");
set_al(-300);
set_level(20);
set_wc(21);
set_ac(9);
set_aggressive(1);
set_chat_chance(10);
load_chat("The Gargoyle says no one shall ever get the cloak of Malichi!\n");
set_a_chat_chance(10);
load_a_chat("The cloak of Malichi will always light the way!\n");
coins = clone_object("obj/money");
coins->set_money(100+(random(100)));
move_object(coins,this_object());
}

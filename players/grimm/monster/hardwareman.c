inherit "obj/monster.talk";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("hardware man");
set_alias("keeper");
set_short("The shop keeper");
set_long("This is a very strong looking hardware store owner.\n");
set_level(16);
set_al(89);
set_wc(20);
set_ac(15);
set_hp(300);
set_aggressive(0);
set_chat_chance(10);
load_chat("I made a special stake for the great vampire killer!\n");
coins = clone_object("obj/money");
coins->set_money(235+(random(100)));
move_object(coins,this_object());
}

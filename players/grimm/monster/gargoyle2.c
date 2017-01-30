inherit "obj/monster.c";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("gargoyle");
set_short("Guardian Gargoyle");
set_long("This is the gaurdian of the cloak of Malichi.\n");
set_level(20);
set_al(-300);
set_wc(30);
set_ac(17);
set_hp(700);  /* he guards a quest item */
set_aggressive(1);
coins = clone_object("obj/money");
coins->set_money(100+(random(100)));
move_object(coins,this_object());
}

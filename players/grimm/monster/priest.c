inherit "obj/monster";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("high priest");
set_long("This is the ghost of the high priest!\n");
set_short("Ghost of High Priest");
set_alias("ghost");
set_level(20);
set_al(500);
set_hp(700); /* guards a quest item */
set_ac(18);
set_wc(30);
set_aggressive(1);
coins = clone_object("obj/money");
coins->set_money(100+(random(200)));
move_object(coins,this_object());
}

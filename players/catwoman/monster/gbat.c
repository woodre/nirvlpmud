inherit "obj/monster.talk";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("bat");
set_short("A giant bat");
set_long("squeek squeek.\n");
set_al(-30);
set_level(12);
set_wc(16);
set_hp(200);
set_ac(9);
set_aggressive(1);
coins = clone_object("obj/money");
coins->set_money(400+(random(300)));
move_object(coins,this_object());
}


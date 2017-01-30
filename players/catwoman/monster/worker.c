inherit "obj/monster.talk";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("worker");
set_short("A construction worker");
set_long("This man is tougher than he looks.\n");
set_al(0);
set_race("human");
set_level(18);
set_wc(26);
set_hp(550);
set_ac(15);
set_aggressive(0);
coins = clone_object("obj/money");
coins->set_money(800 + random(200));
move_object(coins,this_object());
}

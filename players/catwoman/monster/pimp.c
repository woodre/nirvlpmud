inherit "obj/monster.talk";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("pimp");
set_short("A pimp");
set_long("Pimp says: what are you looking at?\n");
set_al(-10);
set_race("human");
set_level(8);
set_wc(12);
set_hp(160);
set_ac(7);
set_aggressive(0);
coins = clone_object("obj/money");
coins->set_money(300);
move_object(coins,this_object());
}

inherit "obj/monster.talk";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("man");
set_alias("gardener");
set_short("Old man");
set_long("This old man is tougher than he looks.\n");
set_al(0);
set_level(8);
set_wc(12);
set_hp(160);
set_ac(7);
set_aggressive(0);
coins = clone_object("obj/money");
coins->set_money(175+(random(200)));
move_object(coins,this_object());
}


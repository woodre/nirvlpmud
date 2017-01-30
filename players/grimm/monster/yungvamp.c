inherit "obj/monster";
object coins,dagger;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("vampire");
set_long("A young vampire made to protect his master Malichi from harm.\n");
set_short("Young vampire");
set_level(6);
set_al(-30);
set_wc(10);
set_aggressive(1);
coins = clone_object("obj/money");
coins->set_money(100+(random(100)));
move_object(coins,this_object());
dagger = clone_object("players/grimm/weapon/dagger1");
move_object(dagger,this_object());
}

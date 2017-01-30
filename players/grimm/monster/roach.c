inherit "obj/monster";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("roach");
set_short("An ugly roach");
set_long("This is a very large and disgusting roach!\n");
set_level(3);
set_aggressive(1);
coins = clone_object("obj/money");
coins->set_money(20+random(60));
move_object(coins,this_object());
}

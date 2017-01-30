inherit "obj/monster";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("vampire");
set_long("This is the Queen of Vampires.  She is a very beutiful, but strong creature.\n");
set_short("Vampire Queen");
set_level(19);
set_aggressive(1);
coins = clone_object("obj/money");
coins->set_money(200+(random(100)));
move_object(coins,this_object());
}

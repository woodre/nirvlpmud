inherit "obj/monster";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("spider");
set_short("A Spider");
set_long("This is a small, pescy little spider!\n");
set_level(2);
set_aggressive(1);
coins = clone_object("obj/money");
coins->set_money(random(30));
move_object(coins,this_object());
}

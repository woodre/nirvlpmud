inherit "obj/monster.talk";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("old man");
set_alias("keeper");
set_short("Time keeper");
set_long("This is the time keeper of the town.  He is very old now.\n");
set_al(40);
set_level(17);
set_aggressive(0);
set_chat_chance(20);
load_chat("Man says: One night i found the castle!  Almost died trying to get in!\n");
coins = clone_object("obj/money");
coins->set_money(234+(random(100)));
move_object(coins,this_object());
}

inherit "obj/monster";
object coins;

reset(arg) {
::reset(arg);
if(arg) return;
set_name("vampire");
set_long("A very big and pissed vampire!\n");
set_short("Evil vampire");
set_level(18);
set_ac(15);
set_wc(26);
set_al(-200);
set_aggressive(1);
coins = clone_object("obj/money");
coins->set_money(800+(random(400)));
move_object(coins,this_object());
}

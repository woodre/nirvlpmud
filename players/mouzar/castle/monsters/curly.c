inherit "obj/monster.c";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("curly");
set_short("Curly Jallisall");
set_long("This is one of three brothers.  He is bald.\n");
set_al(0);
set_level(3);
set_wc(7);
set_ac(4);
set_hp(45);
set_aggressive(0);
coins=clone_object("obj/money");
coins->set_money(100);
move_object(coins,this_object());
}
 
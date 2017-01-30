inherit "obj/monster.c";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("turk");
set_short("Mrs. Turk");
set_long("She is worried that her husband got eaten by a bear or something.\n");
set_al(0);
set_level(2);
set_wc(6);
set_ac(3);
set_hp(40);
set_aggressive(0);
coins=clone_object("obj/money");
coins->set_money(100);
move_object(coins,this_object());
}
 

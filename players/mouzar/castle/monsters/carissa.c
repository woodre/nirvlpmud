inherit "obj/monster.c";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("carissa");
set_short("Stubborn old Carissa");
set_long("She is a old lady who is a real bitch.\n");
set_al(0);
set_level(2);
set_wc(6);
set_ac(3);
set_hp(30);
set_aggressive(0);
coins=clone_object("obj/money");
coins->set_money(90);
move_object(coins,this_object());
}
 

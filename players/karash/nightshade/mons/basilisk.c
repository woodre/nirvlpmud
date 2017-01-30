inherit "obj/monster";
object gold;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("basilisk");
set_short("Basilisk");
set_long("One of the most powerful creatures of the Underdark, the basilisk knows no fear. It can kill instantly with only a breath and turn to stone the hardiest of enemies. It scurries around on six legs and has a long, sharp horn jutting out of its snout.\n");
set_level(20);
set_hp(500);
set_wc(30);
set_ac(17);
gold=clone_object("obj/money");
gold->set_money(5000);
move_object(gold, this_object());
set_al(-2000);
}

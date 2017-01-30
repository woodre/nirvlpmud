
inherit"obj/monster";
reset(arg) {
object money;
object weapon;
::reset(arg);
if(arg) return;
set_name("mom");
set_alias("goblin");
set_short("goblin mom");
set_long(
"This is a goblin momma. Ain't she just Ugly? EEEEKKKKKK!!!!\n");
set_level(5);
set_aggressive(1);
set_race("goblin");
set_chat_chance(10);
load_chat("DON'T TOUCH MY BRATS!!!!\n");
load_chat("Hmmm.... you might taste good broiled.\n");
set_hp(50);
set_al(-3000);
set_wc(5);
set_ac(5);
 set_can_kill(100);
set_random_pick(20);
money = clone_object("obj/money");
money->set_money(25);
move_object(money, this_object());
}

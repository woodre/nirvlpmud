
inherit"obj/monster";
#include "/players/catt/AREAS/base_defines.c"
reset(arg) {
object money;
::reset(arg);
if(arg) return;
set_name("girl");
set_alias("goblin");
set_short("goblin girl");
set_long(
"this is a little goblin girl... may she is lost?\n");
set_level(5);
set_aggressive(1);
set_race("goblin");
set_chat_chance(10);
load_chat("I am lost.... do you know my mommy?\n");
load_chat("TAKE A HIKE BUDDY!!!\n");
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

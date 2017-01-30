
inherit"obj/monster";
#include "/players/catt/AREAS/base_defines.c"
reset(arg) {
object money;
::reset(arg);
if(arg) return;
set_name("slave");
set_alias("slave");
set_short("slobbering slave");
set_long(
"A wimpering slobbering slave.\n");
set_level(5);
set_aggressive(0);
set_chat_chance(10);
load_chat("A slave says: Help us please!!!\n");
load_chat("A slave says: At least kills us.\n");
load_chat("A slave crys: End our misery!\n");
load_chat("A slave whispers: I know of hidden gold...\n");
set_hp(50);
set_al(20);
set_wc(5);
set_ac(15);
 set_can_kill(100);
set_random_pick(20);
money = clone_object("obj/money");
money->set_money(25);
move_object(money, this_object());
}

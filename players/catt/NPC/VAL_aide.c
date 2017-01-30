
inherit"obj/monster";
#include "/players/catt/AREAS/base_defines.c"
reset(arg) {
object money;
object weapon;
::reset(arg);
if(arg) return;
set_name("aide");
set_alias("aide");
set_short("demon masters personal aide");
set_long("This is the Demon Master Brakian's personal aide. He "+
         "doesn't think to much of himself for he dresses poorly "+
         "in a dark blue tunic and black breeches with only his "+
         "dirk of office having any ornamentation.\n");
set_level(15);
set_race("dark elf");
set_hp(1000);
set_wc(12); /* Formerly 0 */
set_ac(10);
set_al(-1000);
set_spell_mess2("");
set_random_pick(5);
money = clone_object("obj/money");
money->set_money(350); /* Formerly 500 */
move_object(money, this_object());
   weapon = clone_object(WPN+"dirkdark.c");
if(weapon) {
move_object(weapon,this_object());
command("wield "+weapon->query_name());
   }
}

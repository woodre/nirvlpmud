/*  Sacagawea  */

#include "defs.h"
inherit "obj/monster";
reset(arg) {

object gold;

::reset(arg);
if(arg) return;
set_name("sacagawea");
set_race("human");
set_short("Sacagawea");
set_long(
	"  'Bird Woman' (c.1787-1812)  Born Shoshone, she was captured \n"+
	"by rival Native Americans and later sold to a French trapper. \n"+
	"Both she and her owner joined the Lewis & Clark Expedition \n"+
	"where she served as a guide. \n");
set_level(16);
set_hp(400);
set_al(30);
set_wc(22);
set_aggressive(0);

move_object(clone_object("players/eurale/Drygulch/OBJ/necklace"),TO);
move_object(clone_object("players/eurale/Drygulch/OBJ/fox"),TO);
init_command("wear necklace");
set_ac(14);

set_chat_chance(15);
  load_chat("Sacagawea whispers:  I miss my people. \n");
  load_chat("Sacagawea quietly hums an indian chant. \n");

gold = clone_object("obj/money");
gold->set_money(random(100)+350);
move_object(gold,this_object());
}

/* the tribal chief  */

#include "defs.h"
inherit "obj/monster";
reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name("chief");
set_race("human");
set_short("the tribe Chief");
set_long(
	"  This is the tribe chief.  His position among his people gives \n"+
	"him power and prestige. \n");
set_hp(425);
set_level(17);
set_al(-50);
set_wc(24);
set_ac(14);
set_aggressive(0);

move_object(clone_object("players/eurale/Drygulch/OBJ/headress"),TO);
init_command("wear headdress");

set_chat_chance(5);
  load_chat("The chief scowls and spits on the floor. \n");

gold = clone_object("obj/money");
gold->set_money(random(100)+450);
move_object(gold,this_object());
}

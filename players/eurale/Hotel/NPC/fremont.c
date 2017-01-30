/*  John Fremont  */

#include "defs.h"
inherit "obj/monster";
reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name("john");
set_race("human");
set_short("John Fremont");
set_alias("fremont");
set_long(
	"  John Charles Fremont (1813-1890)  Explorer known as 'The \n"+
	"Pathfinder', general, governor, senator and anti-slavery \n"+
	"presidential candidate.  Explored and mapped the Oregon Trail. \n");
set_hp(210);
set_level(14);
set_al(30);
set_wc(18);
set_aggressive(0);

move_object(clone_object("players/eurale/Hotel/OBJ/cooncap"),TO);
init_command("wear cap");
set_ac(12);

set_chat_chance(5);
  load_chat("John bellows:  I am running for office, hear ye! \n");
  load_chat("John smiles and waves to you. \n");

gold = clone_object("obj/money");
gold->set_money(random(200)+350);
move_object(gold,this_object());
}

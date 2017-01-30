/*  Jim Bridger  */

#include "defs.h"
inherit "obj/monster";
reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name("jim");
set_race("human");
set_short("Jim Bridger");
set_alias("bridger");
set_long(
	"  James Bridger (1804-1881) was a hunter, trapper, scout, fur \n"+
	"trader, mountain man and teller of tales.  Earliest visitor \n"+
	"to the Great Salt Lake.  Built Fort Bridger on the Oregon \n"+
	"trail. \n");
set_hp(195);
set_level(13);
set_al(-50 + random(75));
set_wc(17);
set_ac(10);
move_object(clone_object("players/eurale/Hotel/OBJ/fox"),TO);
set_aggressive(0);

set_chat_chance(5);
  load_chat("Jim says:  Fine pelts this year. \n");
  load_chat("Jim smiles and looks around the room. \n");
  load_chat("Jim whispers:  I've been up in the hills too long. \n");

gold = clone_object("obj/money");
gold->set_money(random(50)+100);
move_object(gold,this_object());
}

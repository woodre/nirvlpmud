/*  Jim Beckwourth  */

#include "defs.h"
inherit "obj/monster";
reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name("jim");
set_race("human");
set_short("Jim Beckwourth");
set_alias("beckwourth");
set_long(
	"  James Pierson Beckwourth (c.1798-1866)  Black pioneer mountain \n"+
	"man, fur trader and scout.  Lived as a war leader with the Crow. \n"+
	"Early explorer of Beckwourth Pass in the Sierra Nevada mountains. \n");
set_level(17);
set_hp(425);
set_al(-random(100));
set_wc(24);
set_ac(14);
set_aggressive(0);

move_object(clone_object("players/eurale/Hotel/OBJ/bear_fur"),TO);

set_chat_chance(5);
  load_chat("Jim asks:  What'll ya give me for this pelt? \n");
  load_chat("Jim stares at you with steely eyes. \n");
  load_chat("Jim whispers:  I miss my squaw bad! \n");

gold = clone_object("obj/money");
gold->set_money(random(50)+100);
move_object(gold,this_object());
}

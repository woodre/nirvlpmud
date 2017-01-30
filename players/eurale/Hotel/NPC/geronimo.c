/*  Geronimo  */

#include "defs.h"
inherit "obj/monster";
reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name("geronimo");
set_race("human");
set_short("Geronimo");
set_long(
	"  Goyahkla meaning 'One who yawns' (1823-1909)  Chiricahua \n"+
	"Apache war leader.  A fine horseman, guerilla leader and \n"+
	"tactician who led war parties for 30 years.  Widely believed \n"+
	"to have spiritual powers. \n");
set_hp(500);
set_level(20);
set_al(-300);
set_wc(30);
set_aggressive(0);

move_object(clone_object("players/eurale/Hotel/OBJ/headdress"),TO);
init_command("wear headdress");
set_ac(17);

set_chat_chance(5);
  load_chat("Geronimo stares... and says nothing. \n");
  load_chat("Geronimo hisses:  Leave me at once or die. \n");
  load_chat("Geronimo stretches his muscled body. \n");

gold = clone_object("obj/money");
gold->set_money(random(500)+2000);
move_object(gold,this_object());
}

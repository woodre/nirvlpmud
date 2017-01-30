/*  Chief Joseph  */

#include "defs.h"
inherit "obj/monster";
reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name("joseph");
set_alias("chief");
set_race("human");
set_short("Chief Joseph");
set_long(
	"  Hin-mah-too-yah-lat-kekht meaning 'Thunder traveling to loftier \n"+
	"heights.'  (c.1849-1904)  Eloquent, noble Nez Perce chief whose \n"+
	"brilliant tactics allowed his people to fight off the U.S. Army \n"+
	"across several states. \n");
set_hp(180);
set_level(12);
set_al(-50);
set_wc(16);
set_aggressive(1);

move_object(clone_object("players/eurale/Hotel/OBJ/headress"),TO);
init_command("wear headdress");
set_ac(9);

set_chat_chance(5);
  load_chat("Chief Joseph screams:  Prepare to die! \n");
  load_chat("Joseph skillfully dodges your attack. \n");
  load_chat("Joseph lets loose a blood-curdling war cry! \n");

gold = clone_object("obj/money");
gold->set_money(random(50)+50);
move_object(gold,this_object());
}

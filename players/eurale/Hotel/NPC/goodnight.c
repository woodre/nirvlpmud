/*  Charles Goodnight  */

#include "defs.h"
inherit "obj/monster";
reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name("charles");
set_race("human");
set_short("Charles Goodnight");
set_alias("goodnight");
set_long(
	"  Charles Goodnight (1836-1929)  Texas Ranger, Indian fighter, \n"+
	"and pioneer cattle rancher.  Both the Goodnight Trail and the \n"+
	"Goodnight-Loving Trail are named for him.  First person to have \n"+
	"bred 'cattalo.' \n");
set_level(14);
set_hp(210);
set_al(25);
set_wc(18);
set_ac(11);
set_aggressive(0);

move_object(clone_object("players/eurale/Hotel/OBJ/buff_hide"),TO);

set_chat_chance(5);
  load_chat("Charles yawns... \n");

gold = clone_object("obj/money");
gold->set_money(random(50)+250);
move_object(gold,this_object());
}

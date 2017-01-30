/*  Buffalo Bill */

#include "defs.h"
inherit "obj/monster";
reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name("bill");
set_race("human");
set_short("Buffalo Bill");
set_long(
	"  William Frederick Cody (1846-1917).  Frontier scout, pony \n"+
	"express rider, buffalo hunter, army guide, Indian fighter, \n"+
	"flamboyant Wild West showman and hero of Ned Buntline dime \n"+
	"novels. \n");
set_hp(400);
set_level(16);
set_al(-50 + random(100));
set_wc(22);
set_ac(13);
set_aggressive(0);

move_object(clone_object("players/eurale/Hotel/OBJ/buff_hide"),TO);
set_chat_chance(5);
  load_chat("Bill says:  Fewer buffalo every year it seems. \n");
  load_chat("Bill asks:  Won't you sit a spell? \n");

gold = clone_object("obj/money");
gold->set_money(random(100)+100);
move_object(gold,this_object());
}

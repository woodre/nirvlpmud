/*  Bill Pickett  */

#include "defs.h"
inherit "obj/monster";
reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name("bill");
set_race("human");
set_short("Bill Pickett");
set_alias("pickett");
set_long(
	"  Willie M. Pickett (1870-1932)  Fearless black cowboy, rodeo \n"+
	"showman and rancher, said to have invented bulldogging.  Both \n"+
	"Will Rogers and Tom Mix served as his assistants. \n");
set_hp(210);
set_level(14);
set_al(-40 + random(80));
set_wc(18);
set_ac(11);
set_aggressive(0);

move_object(clone_object("players/eurale/Hotel/OBJ/chaps"),TO);
init_command("wear chaps");
move_object(clone_object("players/eurale/Hotel/OBJ/rope"),TO);

set_chat_chance(5);
  load_chat("Bill whispers:  Man, it sure is dark down here. \n");
  load_chat("The cool, dark, dampness makes your skin crawl. \n");

gold = clone_object("obj/money");
gold->set_money(random(150)+300);
move_object(gold,this_object());
}

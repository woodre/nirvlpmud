#include "/players/eurale/Stable/defs.h"
inherit "obj/monster";
reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name("tex");
set_alias("hand");
set_race("human");
set_short("hired hand");
set_long(
	"  This cowboy will take about any job that's available to pay \n"+
	"for his next meal.  He's not afraid of hard work and will give \n"+
	"you a fair day's work for a day's pay. \n");

set_level(13);
set_hp(195 + random(15));
set_wc(15);
set_ac(9);
set_al(-25 + random(51));
set_aggressive(0);

gold = clone_object("obj/money");
gold->set_money(random(100)+700);
move_object(gold,this_object());
}

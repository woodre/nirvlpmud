inherit "obj/monster.talk";
#include "security.h"
#include "living.h"
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_alias("thguard");
set_name("guard");
set_short("Shop guard");
set_long("This Guard has been hired to keep the non-members out.\n he has been known to take a BRIBE!\n");
set_al(0);
set_level(15);
set_wc(20);
set_hp(500 + random(100));
set_ac(16);
set_aggressive(0);
coins = clone_object("obj/money");
coins->set_money(400);
move_object(coins,this_object());
}



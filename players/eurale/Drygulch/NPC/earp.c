/*  Wyatt Earp */

#include "defs.h"
inherit "obj/monster";
reset(arg) {

object gold, star, gun;
::reset(arg);
if(arg) return;
set_name("wyatt");
set_race("human");
set_short("Wyatt Earp");
set_alias("earp");
set_long(
	"  Wyatt Berry Stapp Earp (1848-1917)  Lawman in Wichita, Dodge \n"+
	"City and Tombstone.  Gunfight at the O.K. Coral.  Rode stagecoach\n"+
	"shotgun for Wells Fargo; owned interests in saloons and gambling \n"+
	"halls. \n");
set_hp(525);
set_level(20);
set_al(100);
set_aggressive(0);

move_object(clone_object("players/eurale/Drygulch/OBJ/badge"),TO);
init_command("wear badge");
move_object(clone_object("players/eurale/Drygulch/OBJ/gun"),TO);
init_command("wield revolver");
set_ac(17);
set_wc(30);

set_chat_chance(5);
  load_chat("Wyatt sneers:  You're new around here, ain't ya?\n");
  load_chat("You feel a shiver run up your spine... \n");

gold = clone_object("obj/money");
gold->set_money(random(999)+2000);
move_object(gold,this_object());
}

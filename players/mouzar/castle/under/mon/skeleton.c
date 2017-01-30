#include "/obj/ansi.h"
inherit"obj/monster";
reset(arg) {
object weapon;
::reset(arg);
if(arg) return;
set_name("skeleton");
set_alias("boney");
set_short(WHT+"Skeleton"+NORM);
set_long(
"This walking pile of bones might be missing some muscle and some\n"
+ "brains but it still is a formible foe.\n");
set_level(25);
set_al(0);
set_race("monster");
set_hp(900);
set_wc(20);
set_ac(25);
set_aggressive(1);
weapon = clone_object("/players/mouzar/castle/under/obj/sclub.c");
move_object(weapon,this_object());
}

#include "/players/feldegast/closed/ansi.h"
inherit "obj/monster.c";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("shadow");
set_short(BOLD+BLK+"Shadow"+NORM);
set_long("This shadow seems to move about as though it had a mind of its own.\n");
set_al(0);
set_level(9);
set_wc(15);
set_ac(7);
set_hp(135);
set_aggressive(1);
set_ac_bonus(5); /* Compensate for the lack of coins. -Feldegast 10-9-2000 */
}
 

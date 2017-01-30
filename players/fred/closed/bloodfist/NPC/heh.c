#include "/players/fred/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("heh");
set_alias("heh_id");
set_race("creature");
set_short(BOLD+"Exp. MOB!!!"+NORM);
set_long(
  " Big Dumb massive exp giving freak!\n");
 
set_level(10);
set_hp(250);
set_wc_bonus(100);
set_ac_bonus(100);
set_hp_bonus(100);
set_al(0);
set_ac(7);
set_wc(24);
set_aggressive(0);
}





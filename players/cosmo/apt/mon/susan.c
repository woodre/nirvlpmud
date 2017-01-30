#include "/players/cosmo/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object prize;
  ::reset(arg);
  if(arg) return;

set_name(HIY+"Susan"+NORM);
set_alias("susan");
set_alt_name("susan");
set_race("human");
set_short("Susan");
set_long(
  "Susan is George's girlfriend.  She has a nice figure\n"+
  "and a pretty face with short blonde hair. Susan works\n"+
  "for NBC which is where George met her, when he and\n"+
  "Jerry presented their idea for a sitcom about nothing.\n");

set_level(11);
  set_hp(200);
  set_al(0);
  set_wc(15);
  set_ac(7);
  set_heal(3,20);
  set_aggressive(0);
  set_dead_ob(this_object());

prize = clone_object("/players/cosmo/apt/obj/purse");
move_object(prize,this_object());
}


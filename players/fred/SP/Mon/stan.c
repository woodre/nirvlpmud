#include "/players/fred/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("stan");
set_race("human");
set_short("Stan");
set_long(
  "  Stan is just like most 8 year old kids.  He likes to watch tv,\n"+
  "and play with his dog Sparky.  Only thing that really seperates\n"+
  "him is that he throws up on this girl named Wendy anytime he tries\n"+
  "to talk to her.\n");

add_money(350);
set_level(8);
set_hp(120);
set_al(0);
set_wc(12);
set_ac(7);
set_aggressive(0);

}



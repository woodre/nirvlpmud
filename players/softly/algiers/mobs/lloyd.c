#include "/players/softly/closed/ansi.h"
inherit "/players/softly/closed/std/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return;
   
  set_name("lloyd");
  set_alt_name("shopkeeper");   
  set_alias("lloyd");
  set_long("\nLloyd is a big man who wears his stock like a badge.  On\n\
his head rests a top hat.  He is wearing several sweaters,\n\
a belt with a huge brass buckle, turquoise jeans, bright\n\
white socks, and a pair of black oxfords.  His long grey\n\
hair is held in a pony tail with a leather ornament.  He\n\
is sitting in a chair, next to an old cash register.\n");
  set_short("Lloyd, A shopkeeper");
  set_race("human");
  set_gender("male");
  set_level(12);
  set_attrib("sta", 20);
  set_al(-200);
  set_aggressive(0);
  add_money(500+random(50));
}

#include "/players/eurale/closed/ansi.h"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("willow club");
set_alias("club");
set_short("A willow club");
set_long(
  "This short, thick club was cut from the branch of a large willow\n"+
  "tree.  It has a carved handle and a gnarly knot as it's striking\n"+
  "head.\n");

set_type("club");  /*  sword/knife/club/axe/bow/polearm  */
set_class(16);
set_weight(2);
set_value(600 + random(400));
}

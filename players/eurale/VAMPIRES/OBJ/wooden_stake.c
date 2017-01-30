#include "/players/eurale/closed/ansi.h"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("wooden stake");
set_alias("stake");
set_short("sharp, heavy wooden stake");
set_long(
  "A heavy wooden stake, cut from a hardwood tree.\n");
set_type("knife");  /*  sword/knife/club/axe/bow/polearm  */
set_class(3);
set_weight(1);
set_value(10);
}

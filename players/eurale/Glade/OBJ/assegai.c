#include "/players/eurale/closed/ansi.h"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("assegai");
set_alias("spear");
set_short("Assegai");
set_long(
  "This throwing spear consists of a lancet or barbed head with a\n"+
  "long tang attached to a wooden shaft.  The joint is reinforced\n"+
  "with heavy cord.\n");

set_type("polearm");  /*  sword/knife/club/axe/bow/polearm  */
set_class(15);
set_weight(1);
set_value(800 + random(100));
}

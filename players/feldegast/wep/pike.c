#include "/players/feldegast/closed/ansi.h"
inherit "obj/weapon.c";
reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name("pike");
  set_alias("polearm");
  set_short("Pike");
  set_long(
"This pike consists of a long wooden shaft with a\n"+
"spearhead at the tip.  The pike is considered the\n"+
"best weapon to use against mounted opponents and\n"+
"for that reason was frequently carried by footsoldiers.\n");
  set_type("polearm");
  set_class(16);
  set_weight(4);
  set_value(600);
}

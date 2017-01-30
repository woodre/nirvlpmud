/* weapon for high/mon/mugger.c */
inherit "obj/weapon";
#include "/players/illarion/dfns.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("knife");
  set_short("A small, nasty-looking knife");
  set_long(
"A bone handle lends a solid feel to this short-bladed knife.  In close\n"+
"quarters, with your opponent at your mercy, it would probably prove an\n"+
"excellent weapon.\n");
  set_class(6);
  set_weight(1);
  set_value(200);
}

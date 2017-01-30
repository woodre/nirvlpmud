/* weapon for high/mon/pierson.c */
inherit "obj/weapon";
#include "/players/illarion/dfns.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("broadsword");
  set_alt_name("sword");
  set_short("A grey steel broadsword");
  set_long(
"This sword sports a long, but wide blade, that can take quite a lot of\n"+
"punishment in blocking and dealing blows.  Its main disadvantage is that\n"+
"even sound, it requires an expert to wield it with truly devastating\n"+
"skill.\n");
  set_class(16);
  set_weight(4);
  set_value(1000);
}

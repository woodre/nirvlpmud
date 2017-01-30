/* weapon for high/mon/richie.c */
inherit "obj/weapon";
#include "/players/illarion/dfns.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("rapier");
  set_alt_name("sword");
  set_short("A long steel rapier");
  set_long(
"A leather wrapped hilt provides a secure grip for this light, but still\n"+
"deadly weapon.  The long blade is edged and pointed both, to allow\n"+
"slashing and thrusting styles, and it has been kept sharp.\n");
  set_class(15);
  set_weight(4);
  set_value(800);
}

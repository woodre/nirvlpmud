#include "/players/feldegast/defines.h"
#include "def.h"
inherit PET;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("golem");
  set_alt_name("stone golem");
  set_short(BOLD+BLK+"Stone Golem"+NORM);
  set_long(
"This huge monolith is obviously the work of some magician's spell,\n\
a crude humanoid sketch of a man, but with huge exagerated shoulders\n\
and an unexpressive face.  It's limbs are hewn straight from the rock,\n\
leaving sharp edges and protruding spikes.  In some places, you\n\
suspect that might be intentional, for this mobile statue looks like\n\
it would be a fearsome foe.\n"
  );
  set_gender(0); /* "male","female" */
  set_race("summoned");
  set_level(15);
  set_wc(16);
  set_ac(8);
  set_hp(150+random(40));
  set_al(0);
}

int query_value() { return 3; }

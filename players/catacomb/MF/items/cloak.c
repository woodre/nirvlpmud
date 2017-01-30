#include "/players/catacomb/misc/ansi.h"
inherit "/obj/armor";

reset(arg) {
  if(arg) return;
  set_name("cloak");
  set_short("A long flowing cloak");
  set_long(
    "The long billowing cloak is made of the finest elven silk.  The\n"+
    "Shamot give the cloaks to the maidens as a sort of rite of passage.\n"+
    "The cloak is made of a very light material allowing the wearer \n"+
    "unhindered movement.\n");
  set_type("misc");
  set_ac(1);
  set_weight(1);
  set_value(600);
}

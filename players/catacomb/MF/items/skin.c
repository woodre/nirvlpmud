#include "/players/catacomb/misc/ansi.h"
inherit "/obj/armor";

reset(arg) {
  if(arg) return;
  set_name("skin");
  set_short(HIY+"A long piece of snakeskin"+NORM);
  set_long(
    "  The skin appears to have some decent durability.  From the size\n"+
    "of the skin, the snake must have been huge.  You could easily use\n"+
    "the remnants of this serpent for a cloak.\n");
  set_type("misc");
  set_ac(1);
  set_weight(1);
  set_value(1000);
}

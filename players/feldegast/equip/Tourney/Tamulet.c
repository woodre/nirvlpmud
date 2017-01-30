#include "defs.h"

inherit "obj/armor";

reset(arg) {
  if(arg) return;
  set_name("gorget");
  set_alias("tournament item");
  set_short("A "+BOLD+"silver gorget"+NORM);
  set_long(
    "A plate of armor that protects the neck.  It is embossed with the\n"+
    "crossed swords and shield of the Tournament.\n"
  );
  set_ac(2);
  set_type("amulet");  /* armor,helmet,boots,ring,amulet,shield,misc  */
  set_weight(2);
  set_value(0);
}

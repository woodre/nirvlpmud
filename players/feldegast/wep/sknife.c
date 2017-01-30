#include "defs.h"

inherit "/obj/weapon.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("knife");
  set_alias("serrated knife");
  set_short("Serrated knife");
  set_long(
"This is a sharp blade perhaps six inches long with a serrated\n"+
"blade like a saw.  The silver pommel has a demonic head on it,\n"+
"grinning evilly.\n"
  );
  set_type("knife");
  set_class(14);
  set_weight(1);
  set_value(300+random(100));
}

#include "defs.h"

inherit "/obj/armor.c";

void reset(int arg) {
  if(arg) return;
  set_name("mail");
  set_alias("chainmail");
  set_short("A suit of chainmail");
  set_long(
    "This is a long shirt of chainmail.  It is very heavy, but flexible\n"+
    "and relatively cheap to make.\n"
  );
  set_ac(3);
  set_type("armor");
  set_weight(4);
  set_value(550);
}

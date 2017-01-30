#include "defs.h"
inherit "/obj/armor";

void reset(int arg)
{
  if(arg) return;
  set_name("breastplate");
  set_alias("plate");
  set_short(HIW+"A silver breastplate"+NORM);
  set_long(
   "A thick strong breastplate, suitable for a knight.  It has retained\n"+
   "a mirror-like shine and appears to provide excellent protection.\n"
  );
  set_weight(4);
  set_ac(4);
  set_value(1500);
  set_type("armor");
}

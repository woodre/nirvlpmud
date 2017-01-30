#include "/players/feldegast/defines.h"

inherit "obj/armor";

reset(arg) {
  if(arg) return;
  set_name("hide");
  set_alias("skin");
  set_short("A bear skin");
  set_ac(1);
  set_type("misc");
  set_long(
"This is the hide of a rather large grizzly bear.  It is\n"+
"both thick and warm, and you think you can wear it.\n");
  set_weight(2);
  set_value(950);
}

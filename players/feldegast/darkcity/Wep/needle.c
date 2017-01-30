#include "/players/feldegast/defines.h"
inherit "/obj/weapon";

reset(arg) {
  if(arg) return;
  set_name("needle");
  set_alias("syringe");
  set_short("Mechanical syringe");
  set_long(
"This is an odd-looking mechanical needle.\n"
  );
  set_weight(1);
  set_class(11);
  set_value(50);
}

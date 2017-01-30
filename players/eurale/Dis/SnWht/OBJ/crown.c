/*  the evil queen's crown  */

#include "/open/ansi.h"
inherit "obj/armor";
reset(arg) {
  /* added if(arg) , ::reset() ... ARGGGG */
  ::reset(arg);
  if(arg) return;

set_name("crown");
set_alias("gold crown");
set_short(YEL+"Gold Crown"+NORM);
set_long(
	"A delicate and plain gold crown.\n");
set_ac(1);
set_type("helmet");
set_weight(1);
set_value(1000);
}

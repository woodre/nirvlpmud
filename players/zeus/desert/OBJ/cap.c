#include <ansi.h>
inherit "obj/armor";

reset(arg){
  ::reset(arg);

  set_name("cap");
  set_short(HIW+"A white cap"+NORM);
  set_long(
"This is a fairly well made white cap.  It is woven from a fairly\n"+
"common material and looks pretty bland.  There are bits of sand\n"+
"stuck in it, as though it has been in a desert.\n");
  set_type("helmet");
  set_ac(1);
  set_weight(1);
  set_value(150);
}

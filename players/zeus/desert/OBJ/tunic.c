#include <ansi.h>
inherit "obj/armor";

reset(arg){
  ::reset(arg);

  set_name("tunic");
  set_short(HIW+"A white tunic"+NORM);
  set_long(
"This is a tightly woven white tunic.  It is fairly worn, and has\n"+
"bits of sand in it.  The material is fairly rough making it somewhat\n"+
"uncomfortable to wear, however it does still provide good protection.\n");
  set_type("armor");
  set_ac(3);
  set_weight(2);
  set_value(300);
}

#include <ansi.h>
inherit "obj/armor";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  set_name("diamond necklace");
  set_alias("necklace");
  set_short(HIW+"Diamond Necklace"+NORM);
  set_long("A superb diamond necklace\n");
  set_ac(1);
  set_type("necklace");
  set_weight(1);
  set_value(300);
}

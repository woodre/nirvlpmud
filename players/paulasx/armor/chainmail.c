inherit "/obj/armor.c";
#include <ansi.h>

reset(arg) {
  if(arg) return;
  set_name("chainmail");
  set_alias("mithril chainmail");
  set_short(CYN+"Mithril Chainmail"+NORM);
  set_long(
  "This suit of chainmail is of such superior manufacture that it\n"+
  "is simultaneously protevtice and quite light.\n");
  set_type("armor");
  set_ac(4);
  set_weight(2);
  set_value(3000);
}

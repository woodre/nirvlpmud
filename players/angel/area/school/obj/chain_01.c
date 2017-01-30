#include <ansi.h>
inherit "obj/armor";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  set_name("gold chain");
  set_alias("chain");
  set_short("Gold Chain");
  set_long("\
A gold rope chain, 18k gold. Made from the finest gold.\n"
  );
  set_ac(1);
  set_type("necklace");
  set_weight(1);
  set_value(300);
}
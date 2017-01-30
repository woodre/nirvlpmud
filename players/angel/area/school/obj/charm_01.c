#include <ansi.h>
inherit "/obj/armor";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  set_name("charm bracelet");
  set_alias("bracelet");
  set_short("Charm Bracelet");
  set_long("\
A charm bracelet with 20 charms of different logo's and shapes.\n"
  );
  set_ac(1);
  set_type("bracelet");
  set_weight(1);       
  set_value(300);
}

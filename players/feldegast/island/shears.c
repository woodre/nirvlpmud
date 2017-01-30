#include "/players/feldegast/closed/shortcut.h"
inherit "obj/weapon";
reset(arg) {
  if(arg) return;
  set_name("shears");
  set_short("A rusty pair of shears");
  set_alias("quest_shears");
  set_long(
"This is a pair of rusty iron shears.  They look poorly used,\n"+
"but well made.\n");
  set_type("sword");
  set_class(5);
  set_weight(2);
  set_value(10);
}

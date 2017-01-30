#include "/players/mythos/closed/ansi.h"
inherit "obj/armor";
reset(arg){
  ::reset(arg);
  set_name("skin");
  set_short(BLU+"Dom Skin"+NORM);
  set_alias("dom skin");
  set_type("helmet");
  set_long("This is the colorful skin of a Dom.\n");
  set_ac(2);
  set_weight(1);
  set_value(5000);
}
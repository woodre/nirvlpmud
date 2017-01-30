#include <ansi.h>
inherit "obj/armor";

reset(arg){
  ::reset(arg);

  set_name("boots");
  set_short(HIW+"White elven boots"+NORM);
  set_long(
"These are a nice pair of white elves boots.  Each one comes up\n"+
"fairly high on the leg, providing good protection.  They aren't\n"+
"terribly comfortable looking, but are certainly better than\n"+
"going barefoot.  They seem to have some sand in them though.\n");
  set_type("boots");
  set_ac(1);
  set_weight(1);
  set_value(150);
}

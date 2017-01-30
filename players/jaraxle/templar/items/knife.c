#include "/players/jaraxle/ansi.h"
inherit "obj/weapon.c";



reset(arg){
  ::reset(arg);
  if (arg) return;
set_name("knife");
set_short("a long steel knife");
set_long(
"  This wicked knife is made of steel, and is over a\n"+
"foot long.  A decorative guard protects the handle\n"+
"which is wrapped in a bright clothe.\n");
set_type("knife");
set_alias("knife");
set_class(15);
set_weight(1);
set_value(200);
}


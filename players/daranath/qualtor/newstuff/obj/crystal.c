#include <ansi.h>

inherit "obj/treasure";
reset(arg) {
  if(arg) return;

set_id("gemstone");
set_alias("crystal");
set_short(BOLD+"Small crystal"+NORM);
set_long("A very small, but pure crystal from the body of the Crysmal. Its\n"+
         "value is so high due to its rarity.\n");
set_weight(1);
set_value(500+random(300));
}

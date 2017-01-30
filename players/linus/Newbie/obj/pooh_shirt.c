#include "/players/linus/def.h"
inherit "/obj/armor.c";
id(str) { return str=="shirt" || str=="t-shirt" || str=="red shirt"; }
reset(arg) {
 ::reset(arg);
 if(arg) return;
 set_name(HIR+"A small shirt"+NORM);
 set_short(HIR+"A small shirt"+NORM);
 set_long(
  "A small red t-shirt worn by Winnie the Pooh.  It has several small\n"+
  "honey stains on it.\n");
 set_type("armor");
 set_weight(1);
 set_ac(1);
 set_value(200);
}

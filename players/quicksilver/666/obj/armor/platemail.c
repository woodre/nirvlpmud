#include "/players/quicksilver/666/include/std.h"

inherit ARMOR;

reset(arg) {
     ::reset(arg);
     if(arg) return;
     set_type("armor");
     set_name("platemail");
     set_alias("armor");
     set_ac(4);
     set_weight(7);
     set_short("a suit of platemail");
     set_long("This sturdy platemail was forged from a unique blackened steel found only in\n"+
              "Niurin.  It has the mark of Kern, the master blacksmith, upon it.\n");
}

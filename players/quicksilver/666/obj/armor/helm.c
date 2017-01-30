#include "/players/quicksilver/666/include/std.h"

inherit ARMOR;

reset(arg) {
     ::reset(arg);
     if(arg) return;
     set_type("helmet");
     set_name("helm");
     set_alias("helmet");
     set_ac(1);
     set_weight(3);
     set_short("a closed helm");
     set_long("This sturdy helm was forged from a unique blackened steel found only in\n"+
              "Niurin.  It has the mark of Kern, the master blacksmith, upon it.\n");
}

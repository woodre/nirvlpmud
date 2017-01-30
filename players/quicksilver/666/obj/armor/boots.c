#include "/players/quicksilver/666/include/std.h"

inherit ARMOR;

reset(arg) {
     ::reset(arg);
     if(arg) return;
     set_type("boots");
     set_name("leggings");
     set_alias("boots");
     set_ac(1);
     set_weight(4);
     set_short("a pair of platemail leggings");
     set_long("These platemail leggings were forged from a unique blackened steel found\n"+
              "only in Niurin.  It has the mark of Kern, the master blacksmith, upon it.\n");
}

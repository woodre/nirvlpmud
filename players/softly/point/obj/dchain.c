#include "/players/softly/misc/ansi.h"

inherit "/obj/armor";

reset(arg){
   ::reset(arg);
   if (arg) return;

   set_name("gold chain");
   set_alias("chain");
   set_type("necklace");
   set_short(HIY + "Gold Chain" + NORM);
   set_long("A heavy gold chain with a diamond cross hanging from it.\n");
   set_ac(1);
   set_weight(2);
   set_value(1200);
}



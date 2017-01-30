inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("bow");
   set_alias("skull bow");
   set_short("A "+HIC+"Hair bow"+NORM+" with "+HIW+"Skull "+NORM+"and"+HIW+ " Crossbones"+NORM+"");
   set_long(
      "A small soft blue hair bow with a skull and crossbones in the center of it.\n"
   );
   set_ac(1);
   set_type("helmet");
   set_weight(1);
   set_value(500);
}
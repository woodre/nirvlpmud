inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("whirlwind");
   set_alias("dizzydevil whirlwind");
   set_short(""+MAG+"Dizzy Devil"+NORM+"\'"+MAG+"s"+HIB+" Whirlwind"+NORM+"");
   set_long(
      "A whipping wind that remains in formation. It was once around dizzy devil to soften blows.\n"
   );
   set_ac(1);
   set_type("misc");
   set_weight(1);
   set_value(500);
}
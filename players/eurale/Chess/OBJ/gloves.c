#include "/players/eurale/closed/ansi.h"
#define ETO environment(this_object())
inherit "obj/armor";

reset(arg){
   ::reset(arg);

set_name("gloves");
set_alias("chain gloves");
set_short(YEL+"Platinum chain gloves"+NORM);
set_long(
  "A pair of platinum-colored chain mesh gloves that have a short cuff that\n"+
  "also protects the wrists.\n");

set_type("gloves");
set_ac(1);
set_weight(2);
set_value(1000);
}

do_special(owner) {
if(random(100) < 40) { tell_object(environment(),
  HIY+"The gloves glow as they deflect the blow...\n"+NORM);
  return 1; }
ETO->add_hit_point(1);
return 0;
}

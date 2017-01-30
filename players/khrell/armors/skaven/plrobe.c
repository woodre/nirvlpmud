#include "/players/khrell/ansi.h"
#define ETO environment(this_object())
inherit "obj/armor";

reset(arg){
   ::reset(arg);

   set_name("robes");
   set_alias("robe");
   set_short(YEL+"Plague "+MAG+"Robes"+NORM);
   set_long(
  "The tattered and stained robes of the Clan Pestilens Plague\n"+
  "priests.  It looks servicable as an armor.\n");

   set_type("armor");
   set_ac(4);
   set_weight(2);
   set_value(4000);
   set_params("other|poison",0,20,0);
}

do_special(owner) {
if(random(100) < 30) { tell_object(environment(),
  YEL+"The robes deflect part of the attack.\n"+NORM);
  return 1; }
ETO->add_hit_point(5);
return 0;
}

#include "/players/eurale/closed/ansi.h"
#define ETO environment(this_object())
inherit "obj/armor";

reset(arg){
   ::reset(arg);

set_name("ring");
set_alias("chain gloves");
set_short(GRY+"Grey onyx-cluster ring"+NORM);
set_long(
  "A large ring with a cluster of polished onxy gems attached to its face.\n"+
  "This beautiful ring was a present to the Bishop from his King.\n");

set_type("ring");
set_ac(1);
set_params("magical",1,0,0);
set_params("other|earth",0,10,0);
set_weight(1);
set_value(1100);
}

do_special(owner){
if(random(100) < 40) { tell_object(environment(),
    GRY+"The magic of the ring deflects the blow....\n"+NORM);
  return 1; }
ETO->add_hit_point(1);
return 0;
}

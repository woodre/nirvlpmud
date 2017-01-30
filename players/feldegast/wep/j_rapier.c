#include "/players/feldegast/defines.h"
inherit "/obj/weapon";

reset(arg) {
  if(arg) return;
  set_name("rapier");
  set_alias("jewelled rapier");        
  set_short("A jewelled rapier");
  set_type("sword");
  set_long(
"This is a rapier, a gentleman's weapon, more suited to\n"+
"thrusting and parrying than to the clumsy hacking of\n"+
"common soldiers.  This rapier's hilt and pommel are\n"+
"encrusted with sapphire and rubies.  A golden wolfhead\n"+
"with sapphire eyes is fashioned into the pommel.\n"
  );
  set_weight(4);
  set_class(18);
  set_value(3000);
}

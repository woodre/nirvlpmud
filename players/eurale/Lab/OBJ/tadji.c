#include "/players/eurale/closed/ansi.h"
inherit "obj/weapon";

reset(arg){
  ::reset(arg);
  if (arg) return;

message_hit = ({
	HIR+"carved"+NORM," into "+HIR+"thick bloody slabs"+NORM,
   HIR+"stabbed"+NORM," puncturing a throbbing artery",
	RED+"slashed"+NORM," cleanly across the cheek",
	RED+"stuck"+NORM,", in the chest near their heart",
	BOLD+"CUT"+NORM," on the neck drawing blood",
	GRY+"cut"+NORM," deeply through the thigh",
  GRY+"nicked"+NORM," slightly on the arm with the tadji tip"
	});

set_name("tadji");
set_alias("dagger");
set_alt_name("knife");
set_short(BOLD+"tadji"+NORM);
set_long(
  "This light dagger has a long thin blade with razor edges on both\n"+
  "sides.  The handle is made from some exotic, black wood and cut\n"+
  "in an undulating pattern.  A prized possession which could be bartered.\n");

set_type("knife");
set_class(16);
set_weight(1);
set_value(3000);
set_hit_func(this_object());
set_no_clean(1);
}

query_wear() { return 1; }

weapon_hit(attacker){
if(random(12) < 6) {
  say(BOLD+"The tadji cleanly SLICES through its target..\n"+NORM);
  write(BOLD+"You SLICE through your target with the razor tadji.\n"+NORM);
  return 6; }
return;
}

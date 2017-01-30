#include "/players/eurale/closed/ansi.h"
inherit "obj/weapon";
#define TO this_object()

reset(arg){
  ::reset(arg);
  if (arg) return;

message_hit = ({
  BOLD+"snaps at"+NORM," with sharp, pointed fangs",
  BOLD+"scratches"+NORM," with razor sharp claws",
  BOLD+"nips"+NORM," leaving just a drop of "+HIR+"blood"+NORM,
  HIB+"BITES"+NORM,
   "'s wrist, leaving large "+BOLD+"black"+NORM+" and "+HIB+"blue"+
   NORM+" marks",
  HIY+"SLICES"+NORM," with "+HIY+"yellow, dripping fangs"+NORM,
  HIR+"CHOMPS DOWN"+NORM+" on"," making them wince in PAIN",
  HIR+"BITES and TEARS"+NORM,
   "'s leg, leaving "+HIR+"rough gaping wounds"+NORM
	});

set_alias("wolfangs");
set_long(
  "Sharp, yellowing fangs used to tear and eat meat.\n");

set_class(14);
set_weight(1);
set_value(1);
}

query_wear() { return 1; }
weapon_breaks() { return 1; }
drop() { destruct(this_object()); }
get() { return 0; }

/*
init() {
  if(environment(TO)->is_player()) destruct(TO);
}
*/

short() { return 0; }


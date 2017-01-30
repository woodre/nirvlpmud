#include "/players/eurale/closed/ansi.h"
inherit "obj/weapon";

reset(arg){
  ::reset(arg);
  if (arg) return;

/*
message_hit = ({
	BOLD+"hewed"+NORM," into "+BOLD+RED+"bloody slabs"+NORM,
	BOLD+"cleaved"+NORM,", leaving deep angry gashes",
	BOLD+"hacked"+NORM," into thin slices",
	BOLD+"slashed"+NORM,", laying open their flesh",
	BOLD+"stuck"+NORM," deep into the bowels",
	BOLD+"cut"+NORM," with a surgeon's skill",
	BOLD+"whittled"+NORM," into small shavings"
	});
*/

set_name("broadsword");
set_alias("sword");
set_alt_name("blade");
set_short(HIW+"Pearl"+NORM+"-Hilted "+HIC+"Broadsword"+NORM);
set_long(
	"  This pearl-hilted broadsword has edges like razor blades.\n"+
	"The wide blade is polished to near mirror smoothness and the\n"+
	"pearl handle is wrapped with gold braid.. a beautiful and \n"+
	"very deadly weapon.\n");
set_type("sword");
set_class(18);
set_weight(2);
set_value(1000);
set_hit_func(this_object());
}

weapon_hit(attacker){
if(random(13) > 8) {
say(
 "The broadsword "+BOLD+"CARVES"+NORM+" a huge "+HIR+"GASH"+NORM+
 " in it's target!\n");

write("\n"+
  "Your broadsword "+BOLD+"CARVES"+NORM+" a huge "+HIR+"GASH"+NORM+
  " in your foe!\n\n");
  return 6; }
return;
}

clean_up() { return 0; }

query_wear() {
  int wear;
  wear = 3*hits/25;
  return wear;
}

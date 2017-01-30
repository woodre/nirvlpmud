#include "/players/eurale/closed/ansi.h"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

message_hit = ({
	HIR+"BLUDGEONED"+NORM," into "+BOLD+"unrecognizable pulp"+NORM,
   HIR+"PULVERIZED"+NORM," with a blow from "+BOLD+"HELL"+NORM,
	HIR+"SMASHED"+NORM," with demonic force",
	HIR+"bashed "+NORM,", with a sickening CRUNCH",
	HIR+"bonked "+NORM," leaving a sizeable welt",
	HIR+"clunked"+NORM," just missing a solid blow",
	HIR+"tapped"+NORM," with hardly any result"
	});

set_name("mace");
  set_alias("deathmace");
set_alt_name("death");
set_short(HIR+"Death"+BOLD+"Mace"+NORM);
set_long(
	"This mace has a curved steel shank with a heavy spiked ball on\n"+
	"the end.  The handle is wrapped tightly with soft, thick hide\n"+
	"to provide maximum holding.  The damage done when this weapon\n"+
	"impacts it's target is often lethal and so has earned it the\n"+
	"nickname of '"+HIR+"Death"+BOLD+"Mace"+NORM+"'.\n");
set_type("club");
set_class(18);
set_weight(4);
set_value(2000);
set_no_clean(1);
set_hit_func(this_object());
}

weapon_hit(attacker){
if(random(13) > 7) {
  say(
    "\nThe "+HIR+"Death"+BOLD+"Mace"+NORM+" devastates its target.....\n\n");
  write(
    "\nYou DEVASTATE your target with the "+HIR+"Death"+BOLD+"Mace"+NORM+"!\n");
  return 7; }
return;
}

query_wear() {
  int wear;
  wear = 3*misses/4 + 4*hits/18;
  return wear;
}

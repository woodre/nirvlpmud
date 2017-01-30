#include "/players/eurale/closed/ansi.h"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

message_hit = ({
	HIR+" B L U D G E O N E D "+NORM," into "+BOLD+"unrecognizable pulp"+NORM,
   HIR+" P U L V E R I Z E D "+NORM," with a blow from "+BOLD+"HELL"+NORM,
	HIR+" S M A S H E D "+NORM," with demonic force",
	HIR+" b a s h e d "+NORM,", with a sickening CRUNCH",
	HIR+" b o n k e d "+NORM," leaving a sizeable welt",
	HIR+" clunked "+NORM," just missing a solid blow",
	HIR+" tapped "+NORM," with hardly any result"
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
  set_weight(2);
  set_value(1000);
  set_hit_func(this_object());
}

weapon_hit(attacker){
int W;
W = random(13);
if(W>9)  {
say(
  "\nThe "+HIR+"Death"+BOLD+"Mace"+NORM+" devastates it's target.....\n\n");

write(
  "\nYou DEVASTATE your target with the "+HIR+"Death"+BOLD+"Mace"+NORM+"!\n");
  return 4;
   }
return;
}

init() {
  ::init();
}

query_wear() {
  int wear;
  wear = 3*misses/4 + 4*hits/18;
  return wear;
}

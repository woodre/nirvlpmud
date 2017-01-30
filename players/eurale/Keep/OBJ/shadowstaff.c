#include "/players/eurale/closed/ansi.h"
inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("staff");
set_alias("shadowstaff");
set_short(GRY+"Shadowstaff"+NORM);
set_long(
	"This long, carved wooden pole has a wickedly curved hook on\n"+
	"the end to both restrain and attack opponents.  Once an \n"+
	"opponent has been impaled, they will suffer extreme damage\n"+
	"if they can get away at all.\n");
set_type("club");
set_class(16 + random(4));
set_weight(4);
set_value(900);
set_hit_func(this_object());
}

weapon_hit(attacker){
if(random(13) > 6) {
  say("\nThe shadowstaff "+BOLD+"SMASHES"+NORM+" its target..\n\n");
  write("\nYou "+BOLD+"RUTHLESSLY SMASH"+NORM+" your target...\n\n");
  return 4; }
return;
}

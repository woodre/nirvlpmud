#include "/players/eurale/closed/ansi.h"
inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("scythe");
set_short("A Huge "+BOLD+"Scythe"+NORM);
set_long(
	"This wicked looking weapon has a long, curved blade attached\n"+
	"to a sturdy, thick wooden handle.  The weapon is swung in big\n"+
	"arcs cutting down most in it's path.\n");
set_type("sword");
  set_class(17);
  set_weight(2);
  set_value(500);
}

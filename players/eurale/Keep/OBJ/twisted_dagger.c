#include "/players/eurale/closed/ansi.h"
inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("dagger");
set_alias("twisted dagger");
set_short("A "+BOLD+"Twisted"+NORM+" Dagger");
set_long(
	"  This dagger has a blade of strands of steel twisted and fused\n"+
	"together to form a single weapon.  It's wooden handle provides\n"+
	"a comfortable grip for this close-battle weapon.\n");
set_type("knife");
  set_class(15);
  set_weight(1);
  set_value(350);
}

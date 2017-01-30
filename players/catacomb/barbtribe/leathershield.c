inherit "/obj/armor";
#include "/players/catacomb/misc/ansi.h"

reset(arg) {
  if(arg) return;
  set_name("shield");
  set_short("A small "+HIY+"leather shield"+NORM);
  set_long("  A crude version of a small shield.  It appears\n"+
	"to be well used with all of its scars.");
  set_type("shield");
  set_ac(1);
  set_weight(1);
  set_value(100);
}

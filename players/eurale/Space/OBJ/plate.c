#include "/players/eurale/closed/ansi.h"
inherit "obj/armor";
reset(arg) {

set_name("plate");
set_alias("obsidian plate");
set_short(BOLD+BLK+"Obsidian Plate"+NORM);
set_long(
	"This smooth, obsidian plate will cover your body from\n"+
	"head to foot leaving very little exposed.  It is durable and\n"+
	"one of the toughest armors available.\n");

set_ac(4);
set_type("armor");
set_weight(3);
set_value(1850);
set_no_clean(1);
}


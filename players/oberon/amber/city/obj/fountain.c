#include <ansi.h>
#include "/sys/lib.h"
inherit "obj/treasure";

int active;

reset(arg) {
	::reset(arg);
	if(arg) return;
	active=0;
	set_name("fountain");
	set_short("A fountain");
	set_long("There is a large fountain directly in the center of Amber\n");
	set_weight(9999);
}

init() {
	::init();
	add_action("cmd_drink", "drink");
	/*add_action("cmd_debug", "check");*/
}

cmd_debug(arg) {
	if(arg == "fountain") {
		write("Debug: "+active+"\n");
		return 1;
	}
}

cmd_drink(arg) {
	if(arg == "fountain") {
		write("You drink from the fountain.\n");
		if(random(20) == 1) {
			write("As you drink, a very faint image appears at the bottom of the fountain.\n");
			/* add_item for 'image' */
			active=1;
		}
		say(this_player()->query_name()+" drinks from the fountain.\n");
		return 1;
	}
	return 0;
}

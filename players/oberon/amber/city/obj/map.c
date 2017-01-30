#include <ansi.h>
#include "/sys/lib.h"
inherit "obj/treasure";

reset(arg) {
	::reset(arg);
	if(arg) return;
	set_name("map");
	set_short("A Map of Amber");
	set_long("Provided by the Smith of Amber.\n");
	set_weight(1);
	set_value(500);
}

init() {
	::init();
	add_action("mapread", "read");
}

mapread(arg) {
	if(arg != "map") return;
	write("+---+   +---+   +---+   +---+   +---+   +---+   +---+\n");
	write("|   |---|   |---|   |---| g |---|   |---|   |---|   |\n");
	write("+---+   +---+   +---+   +---+   +---+   +---+   +---+\n");
	write("  |                       |                       |  \n");
	write("+---+                   +---+                   +---+\n");
	write("|   |                   |   |                   |   |\n");
	write("+---+                   +---+                   +---+\n");
	write("  |                       |                       |  \n");
	write("+---+                   +---+   +---+   +---+   +---+\n");
	write("|   |                   |   |   | a |   | w |   |   |\n");
	write("+---+                   +---+   +---+   +---+   +---+\n");
	write("  |                       |       |       |       |  \n");
	write("+---+   +---+   +---+   +---+   +---+   +---+   +---+\n");
	write("| g |---|   |---|   |---| o |---|   |---|   |---| g |\n");
	write("+---+   +---+   +---+   +---+   +---+   +---+   +---+\n");
	write("  |               |                               |  \n");
	write("+---+           +---+                           +---+\n");
	write("|   |           | f |                           |   |\n");
	write("+---+           +---+                           +---+\n");
	write("  |                                               |  \n");
	write("+---+                   +---+                   +---+\n");
	write("|   |                   | i |                   |   |\n");
	write("+---+                   +---+                   +---+\n");
	write("  |                       |                       |  \n");
	write("+---+   +---+   +---+   +---+   +---+   +---+   +---+\n");
	write("|   |---|   |---|   |---| g |---|   |---|   |---|   |\n");
	write("+---+   +---+   +---+   +---+   +---+   +---+   +---+\n");
	return 1;
}

#include "../definitions.h"
#include "/obj/ansi.h"


get() { return 0; }
short() { return "A server named (nameme)"; }
id(str) { return str == "nameme" || str == "server"; }

reset(arg)
{
	move_object(this_object(), DAEMON_HOME);
	if(arg) return;

}

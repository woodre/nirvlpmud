#pragma strict_types
#include "../std.h"
inherit CMD;

status
main(string arg)
{
    object ob;
    
    if (!arg)
      return (notify_fail("Creator of what?\n"), 0);
    if (!(ob = present(arg, this_player())) &&
	(!(ob = environment(this_player())) ||
	 (!ob->id(arg) && !(ob = present(arg, environment(this_player()))))))
      return (notify_fail("There is no such thing here.\n"), 0);
    if (creator(ob))
      write("You sense that " + arg + " is the creation of " +
	    capitalize(creator(ob)) + ".\n");
    else
      write("You sense that " + arg + " has always existed.\n");
    return 1;
}

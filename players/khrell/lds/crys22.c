#include "/players/balowski/std/portable.h"
inherit "obj/clean";
mapping Exits;

reset(arg) {
   if(arg) return;
   Exits=(["north":"/players/llew/closed/crystal/crys25",
           "south":"/players/llew/closed/crystal/crys30",
           "east":"/players/llew/closed/crystal/crys28",
           "west":"/players/llew/closed/crystal/crys27",
           "up":"/players/llew/closed/crystal/crys21"]);
   move_object(clone_object("/players/llew/closed/crystal/big_demon"),this_object());
}
init() {
   int i;
   mixed *ks;
    i = sizeof(ks = m_indices(Exits));
    while (i--)
	add_action("move", ks[i]);
}

long() {
   write("Darkness.\n");
}

short() { return "Darkness"; }

move(string str)
{
    mixed       exit;

    if (exit = Exits[query_verb()]) {
	if (closurep(exit))
	    exit = funcall(exit, str);
	else if (objectp(exit))
	    exit = (mixed) call_other(exit, query_verb(), str);
	if (intp(exit))
	    return exit;
	if (stringp(exit))
	    this_player()->move_player(query_verb() + "#" + exit);
	return 1;
    }
    notify_fail("You cannot go that way.\n");
    return 0;
}

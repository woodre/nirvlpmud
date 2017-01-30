/* fixed by verte */

#pragma strict_types
#include "/players/balowski/lib.h"
#include "../def.h"
inherit ITEM;

void
create()
{
    ::create();
    set_name("dispenser");
    set_short("An Item Dispenser");
    set_long("\
The dispenser is carved in stone, shaped like a grotesque creature with\n\
an enormous head twisted in a hideous grimace.  There are some buttons by\n\
the head's right temple.  Pressing one of them should release an object\n\
from the dispenser.  The dispenser contains various helpful gadgets:\n\
1: Quicktyper     2: Biometer     3: Human skin bag\n\
");
    set_property("prevent_get", "It is much too heavy to lift.\n");
}

void
init()
{
    add_action("cmdPress", "press");
    add_action("cmdPress", "push");
}

status
cmdPress(string arg)
{
    object ob;
    int i, cost; string but;

    if (!arg || !(i = atoi(arg))) {
	notify_fail("Press which button?\n");
	return 0;
    }
    else if (i == 1) {
        if (present("qt", this_player())) {
	    write("You already have the quicktyper.\n");
	    return 1;
	}
	but = "first";
        ob = clone_object("/obj/quicktyper");
    }
    else if (i == 2) {
	if (present("biometer", this_player())) {
	    write("You already have a biometer.\n");
	    return 1;
	}
	but = "second";
	ob = clone_object("/players/mythos/mmisc/biometer");
	cost = 200;
    }
    else if (i == 3) {
      but = "third";
      ob = clone_object(OBJDIR+"bag");
      cost = 500;
    }
    if (cost > (int) this_player()->query_money()) {
	destruct(ob);
	write("You are too poor.\n");
	return 1;
    }
    say(this_player()->query_name() + " pushes a button on the dispenser.\n");
    write("You push the " + but + " button on the dispenser.\n");
    tell_room(environment(), "\
The floor rumbles and a strange hissing sound comes from the mouth of\n\
the trembling dispenser.\n\
Suddenly the dispenser stops hissing and spews out a " +
ob->query_name() + ".\n");
    if (transfer(ob, this_player()))
	transfer(ob, environment());
    this_player()->add_money(-cost);
    return 1;
}

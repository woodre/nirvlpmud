/*
 * Shadowing object for the Shardak guild (Dragnar + Balowski)
 * prevents something from being picked up
 * color change by verte
 */
#include "/players/balowski/lib.h"
#include "../include/ansi.h"
#include "../def.h"
#define QUERY_SHADOW 0
#define START_SHADOW 1
#define DURATION 180

object          Core;           /* the item I am shadowing */

object
shardak_curse(object item)
{
    object      sh;

    if (item) {
	Core = item;
	/* shadow returns 'shadowee' if successful */
	if (sh = shadow(item, START_SHADOW))
	    call_out("lift_curse", DURATION);
	return sh;
    }
    else
	/* for remove_shadow() */
	return this_object();
}

static void
lift_curse()
{
    string s;
    s = ((string)Core->query_name() || (string)Core->short() || "something");
    tell_room(environment(Core), RED+"The flames surrounding " + s + " dwindle.\n"+NORM);
    tell_object(environment(Core), RED+"The flames surrounding " + s + " dwindle.\n"+NORM);
    destruct(this_object());
}

status
get()
{
    if (this_player() &&
	((string)this_player()->query_guild_name() != GUILDNAME))
    {
	write("You burn your fingers severely in the attempt.\n");
	return 0;
    }
    return (status)Core->get();
}

string
short()
{
    string s;
    s = (string)Core->short();
    if (s) return s + RED + " [burning]" + NORM;
}

void
long(string item)
{
    Core->long(item);
    write("It is surrounded by flames.\n");
}

status
clean_up(int refcount)
{
    if (!refcount)
	destruct(this_object());
    else
	return 1;       /* try again later */
}

/*
 * Protection from good.
 * Offers protection against positive aligned creatures
 */
#include "/players/balowski/lib.h"
#include "/players/dragnar/closed/color.h"
#include "../def.h"
#define QUERY_SHADOW 0
#define START_SHADOW 1
#define DURATION 180

object          Core;           /* the item I am shadowing */
int		Power;		/* power of spell left */

object
shardak_pfg(object item)
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
    tell_room(environment(Core), "The flames surrounding " + s + " dwindle.\n");
    tell_object(environment(Core), "The flames surrounding " + s + " dwindle.\n");
    destruct(this_object());
}

string
short()
{
    string s;
    s = (string)Core->short();
    if (s) return s + RED + " [burning]" + NOSTYLE;
}

void
long(string item)
{
    Core->long(item);
    write("It is surrounded by flames.\n");
}

int
hit_player(int damage)
{
}

status
clean_up(int refcount)
{
    if (!refcount)
	destruct(this_object());
    else
	return 1;       /* try again later */
}

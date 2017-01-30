#include "/players/guilds/bards/bard_lib/lib.h"
#pragma strict_types
#pragma save_types

private mapping Props;          /* properties like "mo nagic" :^) */
				/* "no teleport"/"fight area"/"spar area" */
void create()
{
    Props = ([ ]);
}

/*
 * Special properties of the room
 * For instance set "no magic" to 1
 */
mixed query_property(string p)
{
  if(Props)
    return Props[p];
}

void add_property(string p, mixed v)
{
    Props[p] += v;
}

void set_property(string p, mixed v)
{
    Props[p] = v;
}

void set_properties(mapping m)
{
    Props += m;
}

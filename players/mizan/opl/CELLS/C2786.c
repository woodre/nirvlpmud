/* This is a 'stub' object which does nothing much
 * other than to be a placeholder for a wall cell. */
#include "/obj/ansi.h"
reset(int arg)
{
	move_object(this_object(), "/players/mizan/opl/daemons/gridboxDM");
}

string query_current_icon() {
    return  GRY + "W" + NORM;
}

string query_terrain_icon()
{
    return  GRY + "W" + NORM;
}

render_icon()
{
}
query_x() { return 26; }

query_y() { return 23; }

query_index() { return 2786; }

query_sight_range() { return 10; }


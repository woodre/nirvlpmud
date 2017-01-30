inherit "/players/mizan/opl/core/room.c";
#include "/obj/ansi.h"

object mob0, mob1, mob2, mob3, mob4, bonus, bonus2, bonus3, boss, door1, door2;

/* This is a TOP cell of maze, automatically generated. */
/* Please do not make edits to this file as changes would be overwritten */
/* every two weeks by the Perl code which generates this room. Contact */
/* Mizan directly so he can make changes to the Perl code directly. Thanks! */


reset(int arg)
{
	if(arg) return;

	move_object(this_object(), "/players/mizan/opl/daemons/gridboxDM");
	add_property("fight_area");
	short_desc = "The Proving Grounds of the OverPowerLord";
	dest_dir =
	({
		"/players/mizan/opl/CELLS/C2808", "north",
		"/players/mizan/opl/CELLS/C3048", "south",
		"/players/mizan/opl/CELLS/C2929", "east",
	});

	/* Our monster list */

	custom_exits = 1;
	terrain_icon = BGRN + BLK + "m" + NORM;
}

long()
{
	write("    Dirt and what can be assumed is fresh fecal grindings cover the top of\n");
	write("this stone block, and upon it has erupted a large overgrown forest of fungus!\n");
	write("The thick stalks of giant mushrooms form a lush canopy and obscure your view.\n");
	/* This code generates the top-down map of the room we are in */
	write("    There are three obvious exits: north, south and east.\n");

	write(call_other("/players/mizan/opl/daemons/gridDM.c",
	       "render_map",
	       this_object()->query_x(),
	       this_object()->query_y(),
	       this_object()->query_index(),
	       this_object()->query_sight_range() ));

}

query_x() { return 48; }

query_y() { return 24; }

query_index() { return 2928; }

query_sight_range() { return 3; }

query_npc_traversable() { return 1; }
is_forest() { return 1; }

realm() { return "NT"; }


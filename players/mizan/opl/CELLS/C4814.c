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
		"/players/mizan/opl/CELLS/C4694", "north",
		"/players/mizan/opl/CELLS/C4815", "east",
		"/players/mizan/opl/CELLS/C4813", "west",
	});

	/* Our monster list */
	if(!mob0)
	{
		mob0 = clone_object("/players/mizan/opl/beasties/fungus/potato.c");
		move_object(mob0, this_object());
	}

	if(!mob1)
	{
		mob1 = clone_object("/players/mizan/opl/beasties/fungus/wussy_male_vampire.c");
		move_object(mob1, this_object());
	}

	if(!mob2)
	{
		mob2 = clone_object("/players/mizan/opl/beasties/fungus/potato.c");
		move_object(mob2, this_object());
	}

	if(!mob3)
	{
		mob3 = clone_object("/players/mizan/opl/beasties/fungus/big_bunny.c");
		move_object(mob3, this_object());
	}


	custom_exits = 1;
	terrain_icon = BGRN + BLK + BOLD + "M" + NORM;
}

long()
{
	write("    Dirt and what can be assumed is fresh fecal grindings cover the top of\n");
	write("this stone block, and upon it has erupted a large overgrown forest of fungus!\n");
	write("The giant mushroom stalks are significantly thicker and denser around here,\n");
	write("making visibility beyond quite limited and difficult.\n");
	/* This code generates the top-down map of the room we are in */
	write("    There are three obvious exits: north, east and west.\n");

	write(call_other("/players/mizan/opl/daemons/gridDM.c",
	       "render_map",
	       this_object()->query_x(),
	       this_object()->query_y(),
	       this_object()->query_index(),
	       this_object()->query_sight_range() ));

}

query_x() { return 14; }

query_y() { return 40; }

query_index() { return 4814; }

query_sight_range() { return 2; }

query_npc_traversable() { return 1; }
is_forest() { return 1; }

realm() { return "NT"; }


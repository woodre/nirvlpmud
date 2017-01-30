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
		"/players/mizan/opl/CELLS/C703", "north",
		"/players/mizan/opl/CELLS/C943", "south",
		"/players/mizan/opl/CELLS/C822", "west",
	});

	/* Our monster list */
	if(!mob0)
	{
		mob0 = clone_object("/players/mizan/opl/beasties/medium/beano-agent.c");
		move_object(mob0, this_object());
	}

	if(!mob1)
	{
		mob1 = clone_object("/players/mizan/opl/beasties/medium/goblin.c");
		move_object(mob1, this_object());
	}


	custom_exits = 1;
	terrain_icon = BYEL + BLK + "#" + NORM;
}

long()
{
	write("    You are standing on top of a massive stone block, one of many thousands of\n");
	write("which form the sprawing maze that is the Proving Grounds of the OverPowerLord.\n");
	write("There is graffiti on the stone face beneath you. Looking down you see:\n");
	write("\"Some people seem to think that 'damn' is God's last name.\"\n");
	/* This code generates the top-down map of the room we are in */
	write("    There are three obvious exits: north, south and west.\n");

	write(call_other("/players/mizan/opl/daemons/gridDM.c",
	       "render_map",
	       this_object()->query_x(),
	       this_object()->query_y(),
	       this_object()->query_index(),
	       this_object()->query_sight_range() ));

}

query_x() { return 103; }

query_y() { return 6; }

query_index() { return 823; }

query_sight_range() { return 7; }

query_npc_traversable() { return 0; }

realm() { return "NT"; }


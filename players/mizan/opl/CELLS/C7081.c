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
		"/players/mizan/opl/CELLS/C6961", "north",
	});

	/* Our monster list */

	custom_exits = 1;
	terrain_icon = HBRED + BLK + "#" + NORM;
	if(!boss)
	{
		boss = clone_object("/players/mizan/opl/beasties/hard/overpowerlord.c");
		move_object(boss, this_object());
	}

}

long()
{
	write("    You are standing on top of a massive stone block, one of many thousands of\n");
	write("which form the sprawing maze that is the Proving Grounds of the OverPowerLord.\n");
	/* This code generates the top-down map of the room we are in */
	write("    There is one obvious exit: north.\n");

	write(call_other("/players/mizan/opl/daemons/gridDM.c",
	       "render_map",
	       this_object()->query_x(),
	       this_object()->query_y(),
	       this_object()->query_index(),
	       this_object()->query_sight_range() ));

}

query_x() { return 1; }

query_y() { return 59; }

query_index() { return 7081; }

query_sight_range() { return 10; }

query_npc_traversable() { return 0; }

realm() { return "NT"; }


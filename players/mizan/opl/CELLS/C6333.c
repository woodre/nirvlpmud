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
		"/players/mizan/opl/CELLS/C6213", "north",
		"/players/mizan/opl/CELLS/C6453", "south",
	});

	/* Our monster list */

	custom_exits = 1;
	terrain_icon = BYEL + BLK + "#" + NORM;

	if(!bonus)
	{
		bonus = clone_object("/players/mizan/opl/environs/ied.c");
		move_object(bonus, this_object());
		if(1 == random(2)) bonus->light_me();
	}

}

long()
{
	write("    You are standing on top of a massive stone block, one of many thousands of\n");
	write("which form the sprawing maze that is the Proving Grounds of the OverPowerLord.\n");
	write("There is graffiti on the stone face beneath you. Looking down you see:\n");
	write("\"Confucious say:	man who kicked in testicles get left holding bag.\"\n");
	/* This code generates the top-down map of the room we are in */
	write("    There are two obvious exits: north and south.\n");

	write(call_other("/players/mizan/opl/daemons/gridDM.c",
	       "render_map",
	       this_object()->query_x(),
	       this_object()->query_y(),
	       this_object()->query_index(),
	       this_object()->query_sight_range() ));

}

query_x() { return 93; }

query_y() { return 52; }

query_index() { return 6333; }

query_sight_range() { return 7; }

query_npc_traversable() { return 0; }

realm() { return "NT"; }


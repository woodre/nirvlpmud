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
		"/players/mizan/opl/ROOMS/landing", "up",
		"/players/mizan/opl/CELLS/C238", "south",
	});

	/* Our monster list */

	custom_exits = 1;
	terrain_icon = HBYEL + BLK + "#" + NORM;
}

long()
{
	write("    You are standing on top of a massive stone block, one of many thousands of\n");
	write("which form the sprawing maze that is the Proving Grounds of the OverPowerLord.\n");
	write("Surrounding you are walls formed by other identical stone blocks stacked in a\n");
	write("fashion resembling a gaming grid or monstrous childen's block toy of sorts.\n");
	write("A steady breeze wafts by, and try as you may- it is rather hard to get a grasp\n");
	write("of exactly how high the underground ceiling is in this cavern. It seems to be\n");
	write("well over five hundred feet or more- but with no frame of reference, who knows?\n");
	/* This code generates the top-down map of the room we are in */
	write("    There are two obvious exits: up and south.\n");

	write(call_other("/players/mizan/opl/daemons/gridDM.c",
	       "render_map",
	       this_object()->query_x(),
	       this_object()->query_y(),
	       this_object()->query_index(),
	       this_object()->query_sight_range() ));

}

query_x() { return 118; }

query_y() { return 0; }

query_index() { return 118; }

query_sight_range() { return 10; }

query_npc_traversable() { return 0; }

realm() { return "NT"; }


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
		"/players/mizan/opl/CELLS/C4987", "north",
		"/players/mizan/opl/CELLS/C5227", "south",
		"/players/mizan/opl/CELLS/C5108", "east",
		"/players/mizan/opl/CELLS/C5106", "west",
	});

	/* Our monster list */
	if(!mob0)
	{
		mob0 = clone_object("/players/mizan/opl/beasties/sea/octopus.c");
		move_object(mob0, this_object());
	}


	custom_exits = 1;
	terrain_icon = BBLU + BOLD + HIB + "~" + NORM;
}

long()
{
	write("    The top of this stone block has been chopped off, and the volume it\n");
	write("displaced is now filled with water. Deep... cold... salty... smelly water.\n");
	write("The murky depths are teeming with life though. You feel something slimy\n");
	write("brush your legs as you stand in the shallow face of the solid rock shore.\n");
	/* This code generates the top-down map of the room we are in */
	write("    There are four obvious exits: north, south, east and west.\n");

	write(call_other("/players/mizan/opl/daemons/gridDM.c",
	       "render_map",
	       this_object()->query_x(),
	       this_object()->query_y(),
	       this_object()->query_index(),
	       this_object()->query_sight_range() ));

}

query_x() { return 67; }

query_y() { return 42; }

query_index() { return 5107; }

query_sight_range() { return 3; }

query_npc_traversable() { return 0; }

is_water() { return 1; }

realm() { return "NT"; }


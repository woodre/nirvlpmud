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
		"/players/mizan/opl/CELLS/C6878", "north",
		"/players/mizan/opl/CELLS/C6999", "east",
		"/players/mizan/opl/CELLS/C6997", "west",
	});

	/* Our monster list */
	if(!mob1)
	{
		mob1 = clone_object("/players/mizan/opl/environs/lava.c");
		move_object(mob1, this_object());
	}


	custom_exits = 1;
	terrain_icon = HBRED + HIY + "~" + NORM;
}

long()
{
	write("    Hot, bubbling death awaits you as this stone block has been chopped clean\n");
	write("and its empty space is now filled with a pool of glistening, molten lava.\n");
	write("Don't do something stupid like drop your keys in there because if you do,\n");
	write("they're gone... baby they're gone. You might not want to stand too long \n");
	write("in your current position because lava is rather hot (hint, hint). \n");
	/* This code generates the top-down map of the room we are in */
	write("    There are three obvious exits: north, east and west.\n");

	write(call_other("/players/mizan/opl/daemons/gridDM.c",
	       "render_map",
	       this_object()->query_x(),
	       this_object()->query_y(),
	       this_object()->query_index(),
	       this_object()->query_sight_range() ));

}

query_x() { return 38; }

query_y() { return 58; }

query_index() { return 6998; }

query_sight_range() { return 4; }

query_npc_traversable() { return 0; }

is_lava() { return 1; }

realm() { return "NT"; }


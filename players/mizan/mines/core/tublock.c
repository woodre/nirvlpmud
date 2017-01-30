inherit "/room/room.c";
#include "../definitions.h"
#include "/obj/ansi.h"

/* Our member variables */
int my_min_cell_level;
int my_max_cell_level;
string my_master_object;


get() { return 1; }
id(str) { return str == "tublock"; }

reset(arg)
{
	::reset(arg);
	my_min_cell_level = 1;
	my_max_cell_level = 0;
	set_light(1);
}

set_master_object(arg) { my_master_object = arg; }
query_master_object() { return my_master_object; }

set_minimum_level(arg) { my_min_cell_level = arg; }
query_minimum_level() { return my_min_cell_level; }

set_maximum_level(arg) { my_max_cell_level = arg; }
query_maximum_level() { return my_max_cell_level; }


init()
{
	object ob;
	::init();

	if(this_player() &&
	   environment(this_player()) &&
	   environment(this_player()) == this_object() &&
	   this_player()->is_player())
	{
		ob = present("tripod_card", this_player());
		if(!ob ||
		   ob->query_access_level() < my_min_cell_level)
		{
			write(HIY + "\n");
			write("A voice from the shadows says: Sir, I think this one isn't suppos...\n");
			write("Suddenly, a pink laser strikes you in the forehead.\n");
			write("\n\nA booming voice tells you:\n");
			write("  Your access level is not high enough to be in this area...\n");
			write("  We are transporting you back to the Tublock entrance gate.\n");
			write("  Thank you for your stay at the Proving Grounds of the OverPowerLord,\n");
			write("  ...brought to you by Carl's Jr.\n\n");
			write(NORM);
			this_player()->move_player("X#/players/mizan/mines/ROOMS/entrance.c");
		}
	}
}

/** 
 * This object is not a daemon per se, but is inherited to generate daemons.
 * A daemon is created for each level, or section of a level where there is
 * a demand for grid-layout rooms.
 *
 * Loading an area based on the cell system takes several seconds. The reason
 * for this are some bugs that might be inherent to the LPMud driver itself.
 * When all of these steps are tried at once, things get ugly, and corruption
 * errors within cells (like anything set via a set_functionname()) happens.
 *
 */
#include "../definitions.h"
#include "/obj/ansi.h"



#define RANDOM_TERRAIN 	0
#define MAP_FILE	1

#define MAX_GRID_WIDTH	16
#define MAX_GRID_HEIGHT 16

#define IS_NORTH_EDGE	1
#define IS_SOUTH_EDGE	2
#define IS_WEST_EDGE	3
#define IS_EAST_EDGE	4

#define IS_NW_CORNER	5
#define IS_NE_CORNER	6
#define IS_SW_CORNER	7
#define IS_SE_CORNER	8

#define CELL_OBJECT	"/players/mizan/mines/core/cell.c"

string *my_rooms;	/* our array of rooms, 2D but stored in 1D */
int x_dimensions;		/* The W-E size of our grid */
int y_dimensions;		/* The N-S size of our grid */
int total_rooms;		/* This is just width * height */

int my_hazard_chance;
int my_minimum_level;		/* The lowest level required to enter here */
int my_maximum_level;		/* The highest level plyr that can stay in */

int temp_current_row;
status is_allocated;		/* if my_rooms is allocated or not */
status is_loading;		/* If the rooms are in a state of loading. */

string cell_short_desc;
string cell_long_desc;

string monster_filename;
int monster_count;
int monster_spawn_chance;

int spawn_point;

/* these we try to pull from a save_object() */
int map_generation_method;
string map_filename;
int *map_data;
int *lightmap_data;
int map_width;
int map_height;


get() { return 0; }

/*
 * The allocation of a room block is done in a staggered wave over time.
 *
 * Here is what happens:
 *
 * 1) The array containing room blocks is allocated immediately.
 * 2) The is_passable() property is then populated, one second later.
 *    There are some bugs if i don't stagger the changes one callout apart.
 * 3) The neighbors and calculations are then made to each cell.
 * 4) The monsters are then populated into the grid.
 * 5) Items are then introduced in the same manner.
 * 6) Once is load is complete, the 'busy' flag is unset for the whole level.
 *
 * This whole process is slated to take 8 seconds. 
 *
 */

reset(arg)
{
	set_light(1);

	/* it is important to note that classes must set their x and y first
 	 * prior to calling their ::reset() supermethod. */
	if(!arg)
	{
		is_allocated = 0;
		is_loading = 1;

        	if(x_dimensions < 3 || y_dimensions < 3) return;

        	/* here we create our grid */
       		total_rooms = x_dimensions * y_dimensions;

        	my_rooms = allocate(total_rooms);

        	is_allocated = 1;
	        temp_current_row = 0;

        	remove_call_out("sub1_allocate_cells");
	        call_out("sub1_allocate_cells", 1);
		
		remove_call_out("sub2_set_cell_properties");
		call_out("sub2_set_cell_properties", 2);

		remove_call_out("sub3_calculate_neighbors");
		call_out("sub3_calculate_neighbors", 3);

		remove_call_out("sub4_load_monsters");
		call_out("sub4_load_monsters", 4);

		remove_call_out("extra_reset");
		call_out("extra_reset", 5);
	}
}

init()
{

/*
	if(this_player())
	{
		if(this_player() && 
		   living(this_player()) &&
		   environment(this_player()) &&
		   environment(this_player() == this_object()))
		{
			this_player()->move_player("X#" + my_rooms[spawn_point]);
		}
	}
*/
}


is_loading() { return is_loading; }
set_x_dimension(arg) { x_dimensions = arg; }
set_y_dimension(arg) { y_dimensions = arg; }
set_cell_short_desc(arg) { cell_short_desc = arg; }
set_cell_long_desc(arg) { cell_long_desc = arg; }

/* This is an 'insurance policy' if a player somehow gets move_player()'d
 * to the cell manager itself, instead of one of its ancillary rooms.
 */
set_spawn_point(arg) { spawn_point = arg; }

set_map_filename(arg)
{
	map_filename = arg;

	if(restore_object("players/mizan/mines/data/maps/" + map_filename))
	{
		map_generation_method = MAP_FILE;
		x_dimensions = map_width;
		y_dimensions = map_height;
	}
	else map_generation_method = RANDOM_TERRAIN;
}

set_monster_load(file, count, chance)
{
        monster_filename = file;
        monster_count = count;
	monster_spawn_chance = chance;
}

/*
 * What we are doing here is allocating the cells, and cloning them in
 * preparation for use.
 *
 */
sub1_allocate_cells()
{
	int counter;
	object cell;
	object ob;

	for(counter = 0; counter < total_rooms; counter ++)
	{
		cell = clone_object(CELL_OBJECT);
		cell->set_master_object(object_name(this_object()));
		move_object(cell, this_object());
		my_rooms[counter] = object_name(cell);
	}

}

/*
 * Properties are set to the cells here. IF they are done concurrently to
 * the previous method, then sync and corruption errors come up.
 *
 */
sub2_set_cell_properties()
{
	int cursor;
	int terrain;
	int temp;
	int light;
	object ob;

	if(!is_allocated) return 0;
	for(cursor = 0; cursor < total_rooms; cursor ++)
	{
		ob = find_object(my_rooms[cursor]);
		
		if(ob)
		{

			/* this is where we generate terrain */
			if(map_generation_method == MAP_FILE)
			{
				terrain = map_data[cursor];
				light = lightmap_data[cursor];
				
			}
			else if(map_generation_method == RANDOM_TERRAIN)
			{
				terrain = random(4) + 17;
				light = 1;
			}
			else
			{
	                        if(1 == random(6)) terrain = 14;
        	                else terrain = random(4);
				light = 1;
			}

                        ob->set_terrain_type(terrain);
			ob->set_light(light);
                        temp = TERRAIN_DM->get_passable(terrain);
                        ob->set_passable(temp);
		}
	}
}


/* 
 * This is a very basic generator. All it does is populate a level with open
 * space- nothing very sophisticated at all. There is no terrain generation,
 * nothing fancy. This creates a flat series of interconnected rooms.
 *
 */
sub3_calculate_neighbors()
{
	int count_height_y;
	int count_width_x;
	int cursor;
	int temp;
	int terrain;
	object ob;

	/* we aren't allocated yet, so we can't do anything. */
	if(!is_allocated) return 0;

		
	for(cursor = 0; cursor < total_rooms; cursor ++)
	{
		/* This is where we are in the index of room block */
		ob = find_object(my_rooms[cursor]); 
/*
		tell_object(find_player("mizan"), my_rooms[cursor] + "\n");
*/
		if(ob)
		{

			temp = get_neighbor(NORTH, cursor);
			if(temp >= 0) ob->add_exit(my_rooms[temp], "north");

			temp = get_neighbor(SOUTH, cursor);
			if(temp >= 0) ob->add_exit(my_rooms[temp], "south");

			temp = get_neighbor(EAST, cursor);
			if(temp >= 0) ob->add_exit(my_rooms[temp], "east");

			temp = get_neighbor(WEST, cursor);
			if(temp >= 0) ob->add_exit(my_rooms[temp], "west");

			ob->set_short(cell_short_desc);
			ob->set_long(cell_long_desc);

			/* we fill in some other properties by brute force for now */
			ob->set_cell_index(cursor);

		}
	}		
}

sub4_load_monsters()
{
	int i;
	int cursor;
	object ob;

	/* we have to make sure we dont clone monsters where a room has
	 * no exits, or is an inaccessible terrain. */
	for(cursor = 0; cursor < total_rooms; cursor ++)
	{
		ob = find_object(my_rooms[cursor]);
		if(ob->is_passable() || ob->query_exitcount() > 0)
		{
			if(random(100) < monster_spawn_chance)
				ob->set_monster_load(monster_filename, monster_count);
		}
	}
}


/* In other cell managers which are inherited from here, they might do
 * some additional setup. In our superclass, we tell the cell manager that it
 * is done loading. 
 */
extra_reset()
{

	is_loading = 0;
}


/* This method accepts two arguments and returns the location of the neighbor.
 * A non match returns -1.
 *
 * The first argument is the direction that we are looking at. Currently what
 * is supported is NORTH, SOUTH, EAST, or WEST.
 * The second argument is what location we are calling this from.
 *
 * The reason for this is to properly assign exits to each cell based on the
 * terrain type of their respective neighbors. 
 */
get_neighbor(arg, cursor)
{
	int temp;
	object celltemp;

	/* some initial bounds checking */
	if(cursor < 0 || cursor > total_rooms) return -1;

	if(arg == NORTH)
	{
		/* if we get something that is in the first row, then there is no northern neighbor. */
		if(cursor < x_dimensions) return -1;
		else
		{
			celltemp = find_object(my_rooms[cursor - x_dimensions]);
			if(celltemp && celltemp->is_passable())
			return (cursor - x_dimensions);
			else return -1;
		}
	}
	else if(arg == SOUTH)
	{
		/* if we get something that is in the bottom row, then there is no southern neighbor. */
		if(cursor >= (total_rooms - x_dimensions)) return -1;
		else
		{
			celltemp = find_object(my_rooms[cursor + x_dimensions]);
			if(celltemp && celltemp->is_passable())
			return (cursor + x_dimensions);
			else return -1;
		}
	}
	else if(arg == EAST)
	{
		temp = fakemod(cursor);
		if(temp == (x_dimensions - 1)) return -1;
		else
		{
			celltemp = find_object(my_rooms[cursor + 1]);
			if(celltemp && celltemp->is_passable())
			return (cursor + 1);
			else return -1;
		}
	}
	else if(arg == WEST)
	{
		temp = fakemod(cursor);
		if(temp < 1) return -1;
		else
		{
			celltemp = find_object(my_rooms[cursor - 1]);
			if(celltemp && celltemp->is_passable())
			return (cursor - 1);
			else return -1;
		}
	}
	else return -1;
}

get_neighbor_object(arg, cursor)
{
	int temp;
	object ob;

	if(cursor < 0 || cursor > total_rooms) return -1;

	temp = get_neighbor(arg, cursor);
	if(temp == -1) return 0;

	ob = find_object(my_rooms[temp]);
	if(ob) return ob;	
	else return 0;
}

/* This is a simple little function that subtracts down until it runs out,
 * and uses that to get a modulus for us in lieu of floating point support.
 */
fakemod(arg)
{
	int i;

	i = arg;

	/* subtract down until we have our modulus */
	while(i >= x_dimensions) 
	{
		i = i - x_dimensions;
	}

	return i;
}


/**
 * This is what is called from the player's long description. 
 *
 *
 */
render(int current_spot)
{
	int i;
	int j;
	object has_dark_sight;
	string result;
	object card;

	card = present("tripod_card", this_player());
	has_dark_sight = present("dark_sight_object", this_player());

	/* if the player has brief mode of their tripod card on, then
	 * we don't render this. */
	if(!card) return;
	if(card && card->is_brief_mode()) return;

	j = 0;
	result = "\n";

	for(i = 0; i < total_rooms; i ++)
	{
		/* start of a new row */

		/* offset two chars in case i need to use margin */
		result += " ";

		if(current_spot == i)
		{
			/* this would be us */
			result += BWHT + HIBLK + "X" + NORM + " ";
		}
		else if(my_rooms[i]->query_light() < 1)
		{
			if(has_dark_sight)
				result += my_rooms[i]->render() + " ";
			else
				result += "  ";
		}
		else
		{
			/* otherwise we can see */
			result += my_rooms[i]->render() + " ";
		}
		
		j ++;
		if(j >= x_dimensions)
		{
			j = 0;

			/* Before we just close out the display, we
			 * populate first with extra info. 
			 */
			result += "\n";
		}
	}	

	return result;
}

/**
 * This function is like the add_exit() in /room/room.c
 *
 * The four parameters we get are:
 */
add_cell_portal(portal_desc, path, dir, dirback, cellid, visibility)
{
	object cell, target;

	/* We need to do a little sanitizing. */
	if(!portal_desc || !path || !dir || !dirback) return;
	if(cellid < 0 || cellid >= total_rooms) return;

	/* make an object reference to the room in question and start
	 * applying some settings to it */
	cell = find_object(my_rooms[cellid]);
	if(cell)
	{
		if(visibility) cell->flag_portal();
                cell->add_exit(path, dir);
		cell->set_portal_desc(portal_desc);
	}

	/* now we load up the destination room */
	call_other(path, "???");
        target = find_object(path);
        if(path)
	{
		/* TODO: we need to trigger init() on each player that
		 * may be present in the room, so they get the updated exits */
		target->add_exit(my_rooms[cellid], dirback);
	}

}


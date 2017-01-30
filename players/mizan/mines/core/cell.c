inherit "/room/room.c";
#include "../definitions.h"
#include "/obj/ansi.h"

/* Our member variables */
int my_min_cell_level;
int my_max_cell_level;
int terrain_type;
int cell_index;
int is_passable;
int is_portal;		/* if this val is set, then there is a portal exit here */
string portal_desc;
string my_master_object;

string my_monster;
int my_monster_count;
string *my_monster_objs;

get() { return 1; }
id(str) { return str == "cell"; }

reset(arg)
{
	
	if(!arg)
	{
		my_min_cell_level = 1;
		my_max_cell_level = 0;
		is_portal = 0;
		is_passable = 1;
		set_light(1);
		set_no_clean(1);
	}

	/* a patch for now */
	set_light(1);

	/* for now, don't do this indiscriminately */
	if(!arg)
	{
		remove_call_out("spawn_monsters");
		call_out("spawn_monsters", 8);
	}

	::reset(arg);
}

spawn_monsters()
{
	int i;
	object monster;
/*	if(!my_monster || my_monster_count < 1) return;
*/
	if(!my_monster_objs) my_monster_objs = allocate(my_monster_count);

	for(i = 0; i < my_monster_count; i ++)
	{
		if(!my_monster_objs[i] || !find_object(my_monster_objs[i]))
		{
	
			monster = clone_object(my_monster);
			my_monster_objs[i] = object_name(monster);
			move_object(monster, this_object());		

		}

	}
}

set_monster_load(monster_file, count)
{
	my_monster = monster_file;
	my_monster_count = count;
}

query_exitcount() { return sizeof(dest_dir); }

set_master_object(arg) { my_master_object = arg; }
query_master_object() { return my_master_object; }

set_cell_index(arg) { cell_index = arg; }
query_cell_index(arg) { return cell_index; }

set_minimum_level(arg) { my_min_cell_level = arg; }
query_minimum_level() { return my_min_cell_level; }

set_maximum_level(arg) { my_max_cell_level = arg; }
query_maximum_level() { return my_max_cell_level; }

set_terrain_type(arg) { terrain_type = arg; }
query_terrain_type() { return terrain_type; }

flag_portal() { is_portal = 1; }
is_portal() { return is_portal; }

set_passable(arg) { is_passable = arg; }
is_passable()
{
	if(is_portal) return 1;
	else return is_passable;
}

set_portal_desc(arg) { portal_desc = arg; }
query_portal_desc() { return portal_desc; }

/**
 * What's going on here is that the grid layout visible to the player
 * is being rendered as a 'textual' grid that they see in the long
 * description, which updates each time they 'look' or move.
 */
render()
{
	object ob;
	ob = first_inventory(this_object());

	/* certain properties of this cell will override whatever
 	 * is occupying it. 
	 */
	if(is_portal) return TERRAIN_DM->get_icon(10);

	/* i had to do things this way to account for invis */
	while(ob)
	{
		/* the order of operations is simple */
		if(ob->is_boss()) return TERRAIN_DM->get_icon(4);
		else if(ob->is_miniboss()) return TERRAIN_DM->get_icon(5);
		else if(ob->is_vehicle()) return TERRAIN_DM->get_icon(6);
		else if(ob->is_player() && !ob->query_invis()) return TERRAIN_DM->get_icon(7);
/*
		else if(ob->is_npc()) return TERRAIN_DM->get_icon(8);
*/
		else if(ob->query_value() > 100 || ob->is_money()) return TERRAIN_DM->get_icon(9);
		ob = next_inventory(ob);
	}
	
	return TERRAIN_DM->get_icon(terrain_type);
}

long()
{
	::long();
	if(portal_desc) write ("    " + HIW + portal_desc + NORM + "\n");

	write("    ");
/* debug info, don't generally need.

	if(this_player() && this_player()->query_level() > 19)
	{
		write("Index: " + cell_index + " " + object_name(this_object()) + "\n");
		if(is_passable) write ("PT/"); else write ("IMPT/");
		write("\n");
	}
*/

	write("Visible terrain:\n" + my_master_object->render(cell_index) + "\n");
}

init()
{
	object ob;
	::init();

	/* this is an overlay which lets people look at directions. */
	add_action("on_look","look");
	add_action("on_look","l");

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

on_look(arg)
{
	if(!arg) return 0;
	
	if(arg == "n" || arg == "north") return do_look(NORTH);
	else if(arg == "s" || arg == "south") return do_look(SOUTH);
	else if(arg == "e" || arg == "east") return do_look(EAST);
	else if(arg == "w" || arg == "west") return do_look(WEST);
	else return 0;
}

do_look(arg)
{
	object ob;
	int terraintype;
	string message;

	if(!arg) return 0;

	ob = GRID_DM->get_neighbor_object(arg, cell_index);
	write(ob->query_terrain_type());
	if(!ob) message = SYSTEXT_DM->get_emptiness_msg();
	else message = TERRAIN_DM->get_long_desc(ob->query_terrain_type());
/*	message = format(message, 76); */
	write(message + "\n");

	return 1;
}

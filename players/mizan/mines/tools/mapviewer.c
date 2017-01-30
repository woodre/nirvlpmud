#include "../definitions.h"

int *map_data;
int map_width;
int map_height;

id(str) { return str == "mapviewer"; }
get() { return 1; }

short() { return "A Mapviewer"; }
long() { write("Use 'viewmap <filename>'.\n"); }

init()
{
	add_action("viewmap","viewmap");
}

viewmap(arg)
{
	int width;
	int cursor;

	if(!restore_object("players/mizan/mines/data/maps/" + arg))
	{
		write("Map view failed.\n");
		return 1;
	}

	width = 0;
	for(cursor = 0; cursor < sizeof(map_data); cursor ++)
	{
		width ++;
		write(" " + TERRAIN_DM->get_icon(map_data[cursor]) + " ");
		if(width >= map_width)
		{
			write("\n");
			width = 0;
		}

	}

	write("Done.\n");
}

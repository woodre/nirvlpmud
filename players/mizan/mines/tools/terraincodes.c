#include "../definitions.h"
id(str) { return str == "terraincodes"; }
short() { return "Terraincodes"; }
init()
{
	add_action("terraincodes","tc");
}

terraincodes()
{
	int i;
	for(i = 0; i < 20; i ++)
	{
		write("Index: ");
		write(" Terrain desc: " + TERRAIN_DM->get_short_desc(i));
		write(" Passable: " + TERRAIN_DM->get_passable(i));
		write("\n");
	}

	return 1;
}

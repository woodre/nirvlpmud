#include "../definitions.h"
string *my_names;

get() { return 0; }
short() { return "A server named (levels)"; }
id(str) { return str == "levels" || str == "server"; }


get_level_name(arg)
{
	int i;
	if(sscanf(arg, "%d", i) != 1) return "Unknown Area";
	else return my_names[i];
}

reset(int arg)
{
    /* move ourselves home. */
    move_object(this_object(), DAEMON_HOME);

    if(!arg)
    {
	my_names = ({

	"Army's Rabbit Farm - For Newbies Only",
	"Weasel Farm",
	"The Earwaxian Petting Zoo",
	"Beano Junction",
	"The Office - Department of Information Technology",
	"Knobgoblin Central",
		"Land of the Mongrelmen",
		"Cheese Orc Unterland",
		"Un-Named L9 Area",
		"Un-Named L10 Area",
		"Un-Named L11 Area",
		"Un-Named L12 Area",
		"Un-Named L13 Area",
		"Un-Named L14 Area",
		"Un-Named L15 Area",
		"Un-Named L16 Area",
		"Un-Named L17 Area",
		"Un-Named L18 Area",
		"Un-Named L19 Area",
		"Un-Named L20 Area",
		"Un-Named L21 Area",
		"Un-Named L22 Area",
		"Un-Named L23 Area",
		"Un-Named L24 Area",
		"Un-Named L25 Area",
		"Un-Named L26 Area",
		"Un-Named L27 Area",
		"Un-Named L28 Area",
		"Un-Named L29 Area",
		"Un-Named L30 Area",
		"Un-Named L31 Area",
		"Un-Named L32 Area",
		"Un-Named L33 Area",
		"Un-Named L34 Area",
		"Un-Named L35 Area",
		"Un-Named L36 Area",
		"Un-Named L37 Area",
		"Un-Named L38 Area",
		"Un-Named L39 Area",
		"Un-Named L40 Area",
		"Un-Named L41 Area"
	});
    }
}

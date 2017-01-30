#include "../definitions.h"
id(str) { return str == "mobstatview"; }
short() { return "Mobstatview"; }
init()
{
	add_action("mobstatview","mview");
}

mobstatview(arg)
{
	int i;
	if(sscanf(arg, "%d", i) != 1) return 0;
	MOBSTATS_DM->fetch_stats(i);
	return 1;
}


/*
 * FILTER_COLOR (02/12/2011)
 * If a player has their color_ok flag set let them see ansi color.
 */

#include <ansi.h>

string filter_color(string str, string color) {
	return color+str+NORM;
}



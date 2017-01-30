
/*
 * FILTER_COLOR (02/12/2011)
 * Simple wrapper function for colorizing
 */

#include <ansi.h>

string filter_color(string str, string color) {
	return color+str+NORM;
}



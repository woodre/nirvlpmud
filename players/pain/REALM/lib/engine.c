#include "../defs.h"

/*
psuedo code

Determining location
east = current - 1;
west = current + 1;
north = current - 100;
south = current + 100;
northwest = current - 101;
southwest = current + 99;
northeast = current - 99;
southeast = current + 101;

looking
looking a direction should allow you to ascertain if there is anything
in the next "X" rooms in a particular direction.

map
should be able to see your location on a map of "X x X" dimensions

ob=find_object("filepath"); destruct(ob);

*/
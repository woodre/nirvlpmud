#include "std.h"

int cab_is_coming;

init() {
    add_action("west","west");
    add_action("open","open");
    add_action("close","close");
    add_action("enter","enter");
    add_action("enter","in");
    add_action("push","push");
    add_action("push","press");
}

short() {
    return "Villa driveway";
}

long() {
    write("You are on the driveway leading west to the resplendent desert\n");
    write("villa of Quantos Tanthalon. The sun is pleasantly warm here.\n");
    if(!cab_is_coming)
	write("There is a Checker Cab waiting on the driveway\n");
    else if(cab_is_coming)
	write("A cab is driving towards the villa in the distance.\n");
}

open(str) {
    if(str != "door")
	return 0;
    if(call_other("players/quantos/plateau/cab", "query_level", 0) != 3) {

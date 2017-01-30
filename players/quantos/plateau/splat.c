/* #include "std.h" /Pell */

reset (arg) {
    if(!arg)
	set_light(1);
}

init() {
    add_action ("north","north");
    add_action ("south","south");
    add_action ("west","west");
}

north() {
    call_other (this_player(), "move_player", "north#players/quantos/plateau/plat");
    return 1;
}

south() {
    call_other (this_player(), "move_player", "south#players/quantos/plateau/fsplat");
    return 1;
}

west() {
    call_other (this_player(), "move_player", "west#players/quantos/plateau/swplat");
    return 1;
}

long() {
    write ("You are on a vast plateau. To the east you can see an immense\n");
    write ("forest, which is far below you. The plateau continues to the\n");
    write ("north, west, and south.\n");
}

short() {
    return "South plateau";
}

#define NAME "Morgar"
#define DEST "room/clearing"

short() {
    return "To the south lies the base of the tower of the gates";
}

long() {
    write("The tower of the gates is nearby to the south behind some trees.\n");
}

init() {
  add_action("south", "south");
}

south(str) {
    call_other(this_player(), "move_player", "south#players/morgar/base");
    return 1;
}

reset(arg) {
    object facade;
    if (arg)
	return;
    move_object(this_object(), "players/morgar/f1");
    move_object(this_object(), "players/morgar/f2");
/*
    move_object(this_object(), "players/morgar/f3");
*/
    move_object(this_object(), DEST);
}
is_castle() {return 1;}

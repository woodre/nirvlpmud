#define NAME "Jara"
#define DEST "room/south/sforst11"
#include "/players/jara/misc/ansi.h"

id(str) { return str == "ruins" || str == "castle"; }

short() {
    return "The Ruins of a Castle";
}

long() {
    write("The ruins of a great stone castle stand here. The windows have been\n");
    write("shattered, and the gate left open. Thick vines of ivy climb the worn\n");
    write("walls of the castle. You could"+HIW+" enter"+NORM+" the"+HIW+" castle"+NORM+".\n");
}

init() {
  add_action("enter", "enter");
}

enter(str) {
    if (!id(str))
	return 0;
    write("You enter the ruins of the castle.\n");
    this_player()->move_player("into the castle#players/jara/area1/entrance.c");
    return 1;
}

reset(arg) {
    if (arg)
	return;
    move_object(this_object(), DEST);
}
is_castle(){return 1;}

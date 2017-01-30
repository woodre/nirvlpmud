#define NAME "Tallos"
#include "/players/wocket/closed/ansi.h"
#define DEST "room/south/sforst9"
/*
 * This is just the facade to a castle. If you want to enable the
 * "enter" command, move the player to a hall or something (which
 * you have to design yourself).
 * The predefined string DEST is where a player should come when he
 * leaves the castle.
 *
 * This file is loaded automatically from "init_file". We have to move
 * ourself to where we are supposed to be.
 */

id(str) { return str == "enter"; }

short() {
    return "The "+HIY+"7 Tigers Inn"+NORM+"";
}

long() {
    write("This is the "+HIY+"7 Tigers Inn"+NORM+", the greatest of all hotels in the planes.\n");
    write("It exists on several "+HIC+"pla"+HIB+"nes"+NORM+" of existance including this one.  It is\n");
    write("a large "+NORM+""+CYN+"marbel"+NORM+" building with several floors. As you look away and\n");
    write("then back you notice the number of floors has changed. How odd?\n");
}

init() {
    add_action("enter","enter");
}

(str) {
    if (!id(str))
	return 0;
    write("The Inn doors are currently closed. a sign on the door says:\n");
    write("                "+HIB+"()()()()()()()()()()\n");
    write("                ()  "+HIY+"COMING SOON!"+HIB+"  ()\n");
    write("                ()()()()()()()()()()"+NORM+"\n");
    return 1;
}

reset(arg) {
    if (arg)
	return;
    move_object(this_object(), DEST);
}
is_castle(){return 1;}

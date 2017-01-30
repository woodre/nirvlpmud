#include "/players/mosobp/ansi.h"
#define NAME "Gemini"
#define DEST "room/alley"
#define tp this_player()

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

id(str) { return str == "donkey"; }

short() {
    return "A donkey";
}

long() {
write(short()+"\nThe donkey does not like to be punched.\n");
}

init() {
  add_action("donkey_punch", "punch");
}

donkey_punch(str) {
    if (!id(str))
	return 0;
write("You punch the donkey and it kicks you into another timezone!\n");
say(this_player()->query_name()+" punched the donkey and it kicked him into another timezone!\n");
this_player()->move_player("punched the donkey#players/gemini/myarea/room/main");
    return 1;
}

reset(arg) {
    if (arg)
	return;
    move_object(this_object(), DEST);
}
is_castle(){return 1;}

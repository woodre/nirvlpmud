#define NAME "Darkfire"
#define DEST "room/eastroad3"

#include <ansi.h>
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

id(str) { return str == "gates"; }

short() {
    return HIR+"rusty "+HIBLK+"iron gates"+NORM;
}

long() {
    write("You see a set of towering "+HIBLK+"iron gates"+NORM+" covered in\n");
    write(RED+"dark "+HIR+"red streaks"+NORM+" the color of rust mingled with\n");
    write("dried blood. Behind the gates you can see a jumble\n");
    write("of huge, broken granite boulders, "+GRY+"charcoal grey"+NORM+" and\n");
    write("glistening with moisture. Peering through the gaps\n");
    write("between the huge stones, you can just make out the\n");
    write("spires of a city rising high into the air. Some even\n");
    write("appear to be floating, detached from the ground.\n");
}

init() {
    add_action("enter", "enter");
}

enter(str) {
    if (!id(str))
  return 0;
    write("The gates shake and squeak, but will not budge.\n");
    return 1;
}

reset(arg) {
    if (arg)
  return;
    move_object(this_object(), DEST);
}
is_castle(){return 1;}

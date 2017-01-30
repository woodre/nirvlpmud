/*
 * This is just the facade to a castle. If you want to enable the
 * "enter" command, move the player to a hall or something (which
 * you have to design yourself).
 * The predefined string DEST is where a player should come when he
 * leaves the castle.
 *
 * This file is loaded automatically from "init_file". We have to move
 * ourself to where we are supposed to be.
 *
 * - Earwax 9/28/05: Fixed typos, changed path of entrance to AREA
 *                   Added ANSI, and colorized it a little, as well.
 */

#define NAME "Deathmonger"
#define DEST "room/south/sforst5"
#define ENTRANCE "/players/deathmonger/room/castle/entrance.c"
#include <ansi.h>

id(str) { return str == "castle"; }

short() {
    return "There is a volcanic island far to the north"; }

long() {
    write("You enter a dimensional shift.\n");
}

init() {
  add_action("north", "north");
}

north() {
  this_player()->move_player("north#players/deathmonger/entrance.c");
/*
"north#"+ENTRANCE);
*/
    return 1;
}

reset(arg) {
    if (arg)
	return;
    move_object(this_object(), "players/deathmonger/room/stairs");
    move_object(this_object(), "players/deathmonger/room/shop_ent");
/*
    move_object(this_object(), "players/deathmonger/ASSASSIN/booth");
    move_object(this_object(), "players/deathmonger/ASSASSIN/cenguild");
*/
    move_object(this_object(), DEST);
}
is_castle() {return 1;}

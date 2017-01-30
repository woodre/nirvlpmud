#define NAME "Nightshade"
#define DEST "room/station"
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

id(str) { return str == "portal"; }

short() {
return "There is a glowing portal here";
}
is_castle() { return 1; }

long() {
write("The portal seems to be built right into the wall.\n"+
"Inside the portal various colors swirl around. You might\n"+
"be able to enter the portal.\n");
return 1;
}

init() {
  add_action("enter", "enter");
}

enter(str) {
if(!str) return;
if(str == "portal")
{
write("You cautiously enter the portal in the wall.\n");
this_player()->move_player("into the portal#players/nightshade/room/trail");
return 1;
}
}
reset(arg) {
object fark;
    if (arg)
	return;
    move_object(this_object(), DEST);
/* commented out by mizan, error discovered by wizardchild
fark = clone_object("players/nightshade/closed/guild/symbol");
 destruct(fark);
 */
}

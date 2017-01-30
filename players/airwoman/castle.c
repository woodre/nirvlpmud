#define NAME "Airwoman"
#define DEST "room/forest7"
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

id(str) { return str == "fountainhead" || str == "fountain head"; }   

short() {
    return "A FOUNTAINHEAD emerging from the ground...";
}

is_castle() { return 1; }

long() {
    write("A fountainhead spurtting out red hot fire giving a \n"+
	"devilish glare at you.  Stepping closer, you almost\n"+
        "succumb to the intense heat and flame.  There seems to\n"+
	"be a passage way into the fountainhead in the mist of the flames...\n"+
        "Do you dare ENTER the fountainhead despite the deadly flames?\n"+ 
	"(ooo....so intense...kinda like Backdraft...)\n");
}

init() {
  add_action("enter", "enter");
}

enter(str) {
    this_player()->move_player("into the fountain#/players/airwoman/CASTLE/entrance");
    return 1;
}

reset(arg) {

/* quest removed 11/24/97  -Eurale
object quest,room;
room = find_object("room/quest_room");
if(!present("blind_boy",room)) {
   quest = clone_object("obj/quest_obj");
   quest->set_name("blind_boy");
   quest->set_hint("Seek out the Guru Brahmin, 'Ask Guru' to find out your quest.\n");
   move_object(quest,room);
}
*/

    if (arg)
	return;
    move_object(this_object(), DEST);
}

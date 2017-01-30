#define NAME "Fred"
#define DEST "room/south/sforst22"
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

id(str) { return str == "hole"; }

short() {
    return "A mysterious hole";
}

long() {
    write("A large mysterious looking hole.\n");
    write("Perhaps you could enter it to see where it goes.\n");
}

init() {
    add_action("enter", "enter");
}

enter(str) {
    if (id(str))
    write("You fall into a pitch black hole and spin wildly on your way down.\n");
    write("                  You land with a loud *THUD*\n\n");                   

    this_player()->move_player("into the hole#players/fred/forest/Rooms/entrance.c");
        return 1;
}

reset(arg) {
    if (arg)
	return;
    move_object(this_object(), DEST);
    load_it();
}

is_castle(){return 1;}

load_it(){
  clone_object("players/fred/mages/gob.c");
  clone_object("players/fred/closed/bloodfist/gob.c"); 
  clone_object("players/fred/closed/venom/venom.c");
  clone_object("players/chip/venom2/neo_venom.c");
  clone_object("players/chip/closed/other/SATAN/satan_reward.c");
 }
 

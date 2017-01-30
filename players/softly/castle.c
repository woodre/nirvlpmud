#define NAME "Softly"
#define DEST "room/south/sforst2"
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

id(str) { return str == "castle" || str == "signpost"; }

short() {
    return "A worn signpost";
}

long() {
    write("\nTacked atop a faded, splintered signpost is\n"+
	  "a hand lettered sign that reads:\n\n"+
	  "\tSh ning La e -->\n"+
	  "\tRoc y P int L ght - >\n"+
	  "\tAlg ers  ->\n");
}


reset(arg) {
    if (arg)
	return;
    if(!present("n51gn", find_object("room/church")))
      move_object(clone_object("/players/softly/newbie/obj/churchsign.c"), "room/church");
   "/room/adv_guild"->woot(); 
    if(!present("n51gn", find_object("room/adv_guild")))
      move_object(clone_object("/players/softly/newbie/obj/advsign"), "room/adv_guild");

    move_object(this_object(), DEST);
}
is_castle(){return 1;}

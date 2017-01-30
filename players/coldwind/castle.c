#include "/players/coldwind/define.h"
#define NAME "Coldwind"
#define DEST "room/deep_forest1"
/*
 * This is just the facade to a castle. If you want to enable the
 * "enter" command, move the player to a hall or something (which
 * you have to design yourself).
 * The predefined string DEST is where a player should come when he
 * leaves the castle.
 *
 * This file is loaded automatically from "init_file". We have to move
 * ourself to where we are supposed to be.
Do this only once -Bp
#include "/players/coldwind/define.h"
 */

id(str) { return str == "carpet"; }

short() {
    return ""+HIC+"M"+NORM+YEL+"a"+HIW+"g"+HIR+"i"+HIY+"c"+HIG+"a"+HIB+"l"+NORM+BOLD+" Carpet"+NORM+"";
}

long() {
    write("A beautiful carpet floating in the air magically.\n");
    write("Legends say that hundreds of years ago a carpet was\n");
    write("exposed to a magical powder causing it to float from\n"+
	      "realm to realm serving the heros. You maybe able to\n"+
		  "ride the carpet.\n");
}

init() {
  add_action("ride", "ride");
}

ride(str) {
/* Changed this next line w/ notify_fail to ensure the
   'ride' command works properly. - Jaraxle [5/18/03] */
 if(!id(str)){ notify_fail("What?\n"); return 0; }
    say(tpn+" rides the magical carpet.\n");
	move_object(this_player(), "/players/coldwind/desert/rooms/carpet.c");
    say(tpn+" arrives.\n");
	write("You jump on top of the carpet and grins bigly..\n");
    command("look", this_player());

    return 1;
write("Ride what?\n");
return 1; 
}
is_castle(){ return 1; }

reset(arg) {
    if (arg)
        return;
    move_object(this_object(), DEST);
}

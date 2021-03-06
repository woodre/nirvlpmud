#define NAME "Fakir"
#define DEST "room/eastroad5"
#include "/players/fakir/color.h"

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

id(str) { return str == "wheel"; }

short() {
    return CYAN+"Wheel of Time"+OFF;
}

long() {
write("The "+CYAN+"Wheel of Time "+OFF+"turns, and ages come and pass, leaving memories that\n"+
"become legend...legend fades to myth, and even myth is long forgotton when\n"+
"the Age that gave it birth comes again. In one Age, called the Third Age by\n"+
"some, an Age yet to come, an Age long past, a "+RED+"Warrior "+OFF+"'touched' the Wheel.\n"+
"The "+RED+"Warrior "+OFF+"was not the beginning.  There are neither beginnings nor endings\n"+
"to the "+CYAN+"Wheel of Time"+OFF+".  But it was a beginning.\n\n\n"+
"Are you that "+RED+"Warrior"+OFF+"?  "+RED+"~"+OFF+""+CYAN+"Touch Wheel"+OFF+""+RED+"~"+OFF+" and embrace your destiny!\n\n\n"); 
}

init() {
  add_action("touch", "touch");
}

touch(str) {
    if (!id(str))
	return 0;
    write(CYAN+"You touch the Wheel and begin a journey in time."+OFF+"\n\n");
    say(this_player()->query_name()+" touches the Wheel and begins a journey in time.\n");
    tell_room("players/fakir/woods/whroom.c", this_player()->query_name()+" arrives.\n");
    move_object(this_player(),"/players/fakir/woods/whroom.c");
    command("look",this_player());
    return 1;
}

reset(arg) {
    if (arg)
	return;
    destruct(clone_object("/players/fakir/closed/scar"));
    move_object(this_object(), DEST);
}
is_castle(){return 1;}

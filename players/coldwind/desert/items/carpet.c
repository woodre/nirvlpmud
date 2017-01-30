#include "/players/coldwind/define.h"

id(str) { return str == "carpet"; }

short() {
    return ""+HIC+"M"+NORM+YEL+"a"+HIW+"g"+HIR+"i"+HIY+"c"+HIG+"a"+HIB+"l"+NORM+BOLD+" Carpet"+NORM+"";
}

long() {
    write("A beautiful carpet floating in the air magically.\n");
    write("Legends say that hundreds of years ago a carpet was\n");
    write("exposed to a magical powder, causing it to float from\n"+
	      "realm to realm serving the heros. You maybe able to\n"+
		  "ride the carpet.\n");
}

init() {
    add_action("ride", "ride");
}

ride(str) {
    if (!id(str))
	return 0;
    say(tpn+" rides the magical carpet.\n");
	move_object(this_player(), "/players/coldwind/desert/rooms/carpet.c");
    say(tpn+" arrives.\n");
	write("You jump on top of the carpet and grins bigly..\n");
    command("look", this_player());

    return 1;
write("Ride what?\n");
return 1; 
}

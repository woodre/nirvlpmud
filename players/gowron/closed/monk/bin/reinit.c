#include "/players/gowron/closed/monk/def.h"

main() {
	present("new_mrobe", this_player())->init();
	write("Updating your commands...\n");
	
	/* add_user() code was removed			     */
	/* since the daemon is so good now :)		     */
	/* WAS ONLY USED FOR TESTING/UPDATING CHANNEL DAEMON */
	return 1;
}


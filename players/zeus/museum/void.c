inherit "room/room";
#include "/players/zeus/closed/all.h"

reset(arg){
 if(arg) return;

	short_desc = HIW+"A Void"+NORM;
	long_desc =
"You are in a void of darkness...  there is nothing anywhere, at all...\n"+
"You feel as though you are floating, however you feel very heavy...\n"+
"You also feel as though typing 'church' would move you to the church...\n";
	set_light(1);
         dest_dir=({     }); 
}

void init(){
	::init();
	add_action("church_cmd", "church");
}

status church_cmd(){
	write("You are moved to the church.\n");
	TP->MP("church#/room/church.c");
	return 1;
}

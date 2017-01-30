inherit "/players/jareel/room";
#include "/players/jareel/define.h"

reset(arg) {
	if(arg) return;
	set_light(1);
	
	short_desc=(HIW+"Duck Pond"+NORM);
	long_desc=
	""+GRN+"#####"+NORM+"R"+GRN+"##"+BBLU+HIB+"ww"+NORM+GRN+"##"+NORM+"|"+GRN+"##"+NORM+"     The bright sun reflects over the water creating a\n"+
	""+GRN+"##"+NORM+"|-----"+YEL+"B"+NORM+"-----"+GRN+"#"+NORM+"     cascade of dancing light.  Jethro’s bait and tackle,\n"+
	""+GRN+"##"+NORM+"|R"+BBLU+HIB+"www"+NORM+"R"+BBLU+HIB+"ww"+NORM+GRN+"#"+NORM+"|"+GRN+"#"+NORM+BOLD+"X"+NORM+GRN+"#"+NORM+"     is a worn down dilapidated shop laying to the south.\n"+
	""+GRN+"#"+NORM+"-|"+BBLU+HIB+"wwwwwww"+NORM+"R"+NORM+"|"+BBLU+HIB+"w"+NORM+"R"+GRN+"#"+NORM+"     Trees surround the path to the east and west. \n"+
	""+BBLU+HIB+"wwwwwwwwwwwwww"+NORM+GRN+"#"+NORM+"\n";
	
	items = ({
			
			"   ","  ",
			
	});
	
	dest_dir = ({
			"/players/jareel/areas/duck_pond/jethro.c","south",
                        "/players/jareel/areas/duck_pond/road12.c","north",
                        			
			
	});
	
}
init() {
	::init();
	add_action("Search","search");
}

Search(str) {
	
	if(!str) { write("Search what?\n"); return 1; }
	write("You search the "+str+" but find nothing special.\n");
	say(this_player()->query_name()+" searches around for something.\n");
	return 1;
}
